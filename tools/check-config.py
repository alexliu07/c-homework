#!/usr/bin/env python3
"""校验 VS Code 配置 / Makefile / 目录布局是否自洽（纯命令行，不需要装 VS Code）。

检查项：
  1. .vscode 下所有 .json 可解析
  2. 任务 label 唯一；launch.json 的 preLaunchTask 都能在 tasks.json 找到
  3. launch.json 的 program 与编译任务的 -o 输出是同一个路径模板
  4. 该输出目录与 Makefile 的 BUILD 目录一致
  5. compilerPath / miDebuggerPath / gdb 是否可用
  6. 单文件布局：仓库根目录有 .c，且没有把作业塞进子目录
  7. 必备文件齐全
"""
from __future__ import annotations

import json
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
VSCODE = ROOT / ".vscode"
errors: list[str] = []
notes: list[str] = []


def load(p: Path):
    try:
        return json.loads(p.read_text(encoding="utf-8"))
    except Exception as exc:  # noqa: BLE001
        errors.append(f"{p.relative_to(ROOT)} 无法解析为 JSON: {exc}")
        return None


def main() -> int:
    tasks_cfg = load(VSCODE / "tasks.json")
    launch_cfg = load(VSCODE / "launch.json")
    props = load(VSCODE / "c_cpp_properties.json")
    settings = load(VSCODE / "settings.json")
    exts = load(VSCODE / "extensions.json")
    if not all([tasks_cfg, launch_cfg, props, settings, exts]):
        return report()

    tasks = tasks_cfg.get("tasks", [])
    labels = [t.get("label") for t in tasks]
    dupes = {l for l in labels if labels.count(l) > 1}
    if dupes:
        errors.append(f"tasks.json 存在重复 label: {sorted(dupes)}")

    for cfg in launch_cfg.get("configurations", []):
        pre = cfg.get("preLaunchTask")
        if pre and pre not in labels:
            errors.append(f"launch 配置 {cfg.get('name')!r} 的 preLaunchTask {pre!r} 在 tasks.json 中不存在")
        if cfg.get("MIMode") == "gdb":
            mi = cfg.get("miDebuggerPath")
            if mi and not Path(mi).exists():
                errors.append(f"miDebuggerPath 不存在: {mi}")
            elif not mi and not shutil.which("gdb"):
                notes.append("未设置 miDebuggerPath 且 PATH 中找不到 gdb —— 调试会失败")

    build_task = next((t for t in tasks if t.get("label") == "gcc: 编译当前文件"), None)
    if build_task is None:
        errors.append("找不到任务 'gcc: 编译当前文件'")
    else:
        args = build_task.get("args", [])
        if "-o" not in args:
            errors.append("编译任务缺少 -o 输出参数")
        else:
            out = args[args.index("-o") + 1].replace("${workspaceFolder}/", "")
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
        flags = [a for a in args if a.startswith("-")]
        for need in ("-g", "-std=c11", "-Wall", "-Wextra"):
            if need not in flags:
                notes.append(f"编译任务未使用 {need}（调试/规范性会受影响）")

    # Makefile 的 BUILD 目录要和 VS Code 产物目录一致
    mk = (ROOT / "Makefile").read_text(encoding="utf-8") if (ROOT / "Makefile").exists() else ""
    m = re.search(r"^BUILD\s*:?=\s*(\S+)", mk, re.M)
    if not m:
        errors.append("Makefile 中找不到 BUILD 变量")
    else:
        build_dir = m.group(1)
        if build_dir != "build":
            errors.append(f"Makefile 的 BUILD={build_dir}，与 .vscode 约定的 build/ 不一致")

    cfg0 = props.get("configurations", [{}])[0]
    compiler = cfg0.get("compilerPath")
    if compiler and not Path(compiler).exists() and not shutil.which(compiler):
        notes.append(f"c_cpp_properties.json 的 compilerPath 本机不存在: {compiler}（其它平台请自行修改）")
    if settings.get("C_Cpp.default.compilerPath") != compiler:
        notes.append("settings.json 与 c_cpp_properties.json 的 compilerPath 不一致")

    if "ms-vscode.cpptools" not in exts.get("recommendations", []):
        errors.append("extensions.json 未推荐 ms-vscode.cpptools（调试依赖它）")

    # 单文件布局检查
    root_c = sorted(p.name for p in ROOT.glob("*.c"))
    if not root_c:
        notes.append("根目录还没有 .c 作业文件，用 ./newhw.sh hw01 建一个")
    nested = [str(p.relative_to(ROOT)) for p in ROOT.rglob("*.c") if p.parent != ROOT and "templates" not in p.parts and "build" not in p.parts]
    if nested:
        notes.append(f"发现不在根目录的 .c: {nested}（单文件布局下作业应直接放根目录）")

    for must in ("README.md", "Makefile", "templates/main.c", "newhw.sh", "tools/check-config.py"):
        if not (ROOT / must).exists():
            errors.append(f"缺少文件: {must}")

    print(f"根目录作业文件: {', '.join(root_c) if root_c else '（无）'}")
    return report()


def report() -> int:
    for n in notes:
        print(f"[提示] {n}")
    for e in errors:
        print(f"[错误] {e}")
    if errors:
        print(f"\n配置检查失败：{len(errors)} 个错误")
        return 1
    print("配置检查通过：.vscode / Makefile / 目录布局自洽，编译与调试路径一致。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
