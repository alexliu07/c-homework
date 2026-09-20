#!/usr/bin/env python3
"""校验 .vscode 配置 / Makefile / 目录布局是否自洽（纯命令行，不需要装 VS Code）。

检查项：
  1. .vscode 下所有 .json 可解析；不再残留微软 C/C++ 插件的 c_cpp_properties.json 与 C_Cpp.* 设置
  2. 任务 label 唯一；launch.json 的 preLaunchTask 都能在 tasks.json 找到
  3. launch.json 的 program 与编译任务的 -o 输出是同一个路径模板
  4. 编译任务的标志与 Makefile 的 CFLAGS / LDLIBS 一致（避免两边漂移）
  5. 推荐扩展是 clangd + CodeLLDB；调试配置用 lldb
  6. 布局：作业是 programs/ 下的一层 .c 文件，没有子目录
  7. 必备文件齐全
"""
from __future__ import annotations

import json
import re
import subprocess
import shlex
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
VSCODE = ROOT / ".vscode"
PROGRAMS = ROOT / "programs"
errors: list[str] = []
notes: list[str] = []


def load(p: Path):
    try:
        return json.loads(p.read_text(encoding="utf-8"))
    except Exception as exc:  # noqa: BLE001
        errors.append(f"{p.relative_to(ROOT)} 无法解析为 JSON: {exc}")
        return None


def makefile_var(name: str) -> list[str]:
    mk = ROOT / "Makefile"
    if not mk.exists():
        return []
    m = re.search(rf"^{name}\s*\??=\s*(.+)$", mk.read_text(encoding="utf-8"), re.M)
    if not m:
        return []
    return shlex.split(m.group(1).split("#")[0].strip())


def main() -> int:
    tasks_cfg = load(VSCODE / "tasks.json")
    launch_cfg = load(VSCODE / "launch.json")
    settings = load(VSCODE / "settings.json")
    exts = load(VSCODE / "extensions.json")
    if not all([tasks_cfg, launch_cfg, settings, exts]):
        return report()

    if (VSCODE / "c_cpp_properties.json").exists():
        errors.append("仍存在 .vscode/c_cpp_properties.json —— 那是微软 C/C++ 插件的配置，用 clangd 后应删除")
    legacy = sorted(k for k in settings if k.startswith("C_Cpp."))
    if legacy:
        errors.append(f"settings.json 里还留着微软插件的设置 {legacy}，应删除")

    tasks = tasks_cfg.get("tasks", [])
    labels = [t.get("label") for t in tasks]
    dupes = {l for l in labels if labels.count(l) > 1}
    if dupes:
        errors.append(f"tasks.json 存在重复 label: {sorted(dupes)}")

    for cfg in launch_cfg.get("configurations", []):
        pre = cfg.get("preLaunchTask")
        if pre and pre not in labels:
            errors.append(f"launch 配置 {cfg.get('name')!r} 的 preLaunchTask {pre!r} 在 tasks.json 中不存在")
        if cfg.get("type") == "cppdbg":
            notes.append(f"调试配置 {cfg.get('name')!r} 仍是 cppdbg（需要微软 C/C++ 插件，会与 clangd 抢语言服务）")

    build_task = next((t for t in tasks if t.get("label") == "gcc: 编译当前文件"), None)
    if build_task is None:
        errors.append("找不到任务 'gcc: 编译当前文件'")
    else:
        # 任务可能写成 "command": "gcc" + "args": [...]，也可能写成整条 shell 命令，两种都要支持
        cmdline = " ".join([str(build_task.get("command", "")), *[str(a) for a in build_task.get("args", [])]])
        m_out = re.search(r"-o\s+\"?([^\s\"]+)\"?", cmdline)
        if not m_out:
            errors.append("编译任务缺少 -o 输出参数")
        else:
            out = m_out.group(1).replace("${workspaceFolder}/", "")
            if not out.startswith("build/"):
                errors.append(f"编译产物不在 build/ 下: {out}")
            for cfg in launch_cfg.get("configurations", []):
                prog = cfg.get("program", "")
                if "${fileBasenameNoExtension}" in prog:
                    rel_prog = prog.replace("${workspaceFolder}/", "")
                    if rel_prog != out:
                        errors.append(
                            "launch.json 的 program 与编译任务输出不一致:\n"
                            f"    launch: {rel_prog}\n    task  : {out}"
                        )
            # 产物目录不会自己出现：编译任务必须自己建目录，否则新克隆 / make clean 后一按 F5 就报
            # "cannot open output file build/xxx"
            if "mkdir" not in cmdline:
                errors.append("编译任务没有先创建 build/ 目录 —— 新克隆或 make clean 之后编译会直接失败")
        for var in ("CFLAGS", "LDLIBS"):
            for flag in makefile_var(var):
                if flag not in cmdline:
                    errors.append(f"Makefile 的 {var} 里有 {flag}，但编译任务里没有（两边会漂移）")

    mk = (ROOT / "Makefile").read_text(encoding="utf-8") if (ROOT / "Makefile").exists() else ""
    m = re.search(r"^BUILD\s*:?=\s*(\S+)", mk, re.M)
    if not m:
        errors.append("Makefile 中找不到 BUILD 变量")
    elif m.group(1) != "build":
        errors.append(f"Makefile 的 BUILD={m.group(1)}，与 .vscode 约定的 build/ 不一致")
    if "programs/*.c" not in mk:
        errors.append("Makefile 未从 programs/*.c 收集源文件")
    if "notdir" not in mk:
        notes.append("Makefile 未用 $(notdir ...)，build/ 里可能带上源目录层级，与 .vscode 的 build/<文件名> 不一致")

    # 真跑一次 make list，确认产物路径与 .vscode 约定的 build/<文件名> 完全一致
    if shutil.which("make") and PROGRAMS.is_dir():
        expect = [f"build/{p.stem}" for p in sorted(PROGRAMS.glob("*.c"))]
        res = subprocess.run(["make", "-s", "list"], cwd=ROOT, capture_output=True, text=True)
        got = [l.strip() for l in res.stdout.splitlines() if l.strip()]
        if sorted(got) != sorted(expect):
            errors.append(
                "make list 的产物与预期不一致:\n"
                f"    make: {', '.join(got) or '(空)'}\n"
                f"    预期: {', '.join(expect) or '(空)'}"
            )
        elif res.returncode != 0:
            errors.append(f"make list 退出码 {res.returncode}: {res.stderr.strip()[:200]}")
        else:
            print(f"make list: {', '.join(got) if got else '（无产物）'}")

    clangd_args = settings.get("clangd.arguments", [])
    if not clangd_args:
        errors.append("settings.json 未配置 clangd.arguments")
    if "--clang-tidy" not in clangd_args:
        notes.append("clangd.arguments 未启用 --clang-tidy（需要 clang-tidy 才有静态检查提示）")
    if "[c]" not in settings:
        notes.append("settings.json 未设置 [c] 语言级配置（clangd 作为格式化器）")

    rec = exts.get("recommendations", [])
    if "llvm-vs-code-extensions.vscode-clangd" not in rec:
        errors.append("extensions.json 未推荐 llvm-vs-code-extensions.vscode-clangd")
    if "vadimcn.vscode-lldb" not in rec:
        errors.append("extensions.json 未推荐 vadimcn.vscode-lldb（调试用）")
    if "ms-vscode.cpptools" in rec:
        errors.append("extensions.json 仍推荐 ms-vscode.cpptools（会与 clangd 抢语言服务）")

    if not shutil.which("clangd"):
        notes.append("本机 PATH 里没有 clangd（VS Code 的 clangd 扩展可用 clangd.path 指定或自行下载）")
    if not shutil.which("lldb"):
        notes.append("本机 PATH 里没有 lldb（CodeLLDB 自带，装系统 lldb 亦可）")

    if not PROGRAMS.is_dir():
        errors.append("缺少 programs/ 目录")
    else:
        srcs = sorted(p.name for p in PROGRAMS.glob("*.c"))
        subdirs = [str(p.relative_to(ROOT)) for p in PROGRAMS.rglob("*") if p.is_dir()]
        if subdirs:
            notes.append(f"programs/ 下出现子目录: {subdirs}（约定是单层 .c 文件）")
        print(f"programs/ 下作业文件: {', '.join(srcs) if srcs else '（无）'}")
    stray = [
        str(p.relative_to(ROOT))
        for p in ROOT.rglob("*.c")
        if p.parent != PROGRAMS and "templates" not in p.parts and "build" not in p.parts
    ]
    if stray:
        notes.append(f"发现不在 programs/ 下的 .c: {stray}")

    for must in ("README.md", "Makefile", "templates/main.c", "newhw.sh", ".clang-format", "tools/check-config.py"):
        if not (ROOT / must).exists():
            errors.append(f"缺少文件: {must}")

    return report()


def report() -> int:
    for n in notes:
        print(f"[提示] {n}")
    for e in errors:
        print(f"[错误] {e}")
    if errors:
        print(f"\n配置检查失败：{len(errors)} 个错误")
        return 1
    print("配置检查通过：.vscode 配置 / Makefile / 目录布局自洽，编译与调试路径一致。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
