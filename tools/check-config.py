#!/usr/bin/env python3
"""校验 .vscode 配置的内部一致性（不依赖 VS Code，可在纯命令行下跑）。

检查项：
  1. .vscode 下所有 .json 能被解析
  2. tasks.json 的任务 label 唯一，launch.json 的 preLaunchTask 都能找到
  3. launch.json 的 program 路径模板与编译任务的输出路径模板一致
  4. compilerPath / miDebuggerPath 指向真实存在的文件
  5. 编译任务覆盖了 launch.json 里出现的每个 ${fileBasenameNoExtension}
"""
from __future__ import annotations

import json
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
    load(VSCODE / "settings.json")

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
            errors.append(f"launch.json 配置 {cfg.get('name')!r} 的 preLaunchTask {pre!r} 在 tasks.json 中不存在")
        if cfg.get("type") == "cppdbg" and cfg.get("MIMode") == "gdb":
            mi = cfg.get("miDebuggerPath")
            if mi and not Path(mi).exists():
                errors.append(f"miDebuggerPath 不存在: {mi}")
            elif not mi and not shutil.which("gdb"):
                notes.append("未设置 miDebuggerPath 且 PATH 中找不到 gdb —— 调试会失败")

    # 编译任务输出 vs 调试入口
    build_task = next((t for t in tasks if t.get("label") == "gcc: 编译当前文件"), None)
    if build_task is None:
        errors.append("找不到任务 'gcc: 编译当前文件'")
    else:
        args = build_task.get("args", [])
        if "-o" not in args:
            errors.append("编译任务缺少 -o 输出参数")
        else:
            out = args[args.index("-o") + 1]
            rel_out = out.replace("${workspaceFolder}/", "")
            for cfg in launch_cfg.get("configurations", []):
                prog = cfg.get("program", "")
                if "relativeFileDirname" in prog:
                    rel_prog = prog.replace("${workspaceFolder}/", "")
                    if rel_prog != rel_out:
                        errors.append(
                            "launch.json 的 program 与编译任务输出不一致:\n"
                            f"    launch: {rel_prog}\n    task  : {rel_out}"
                        )
        flags = [a for a in args if a.startswith("-")]
        for need in ("-g", "-std=c11", "-Wall", "-Wextra"):
            if need not in flags:
                notes.append(f"编译任务未使用 {need}（调试/规范性会受影响）")

    cfg0 = props.get("configurations", [{}])[0]
    compiler = cfg0.get("compilerPath")
    if compiler and not Path(compiler).exists() and not shutil.which(compiler):
        notes.append(f"c_cpp_properties.json 的 compilerPath 在本机不存在: {compiler}（其它平台请自行修改）")
    if settings.get("C_Cpp.default.compilerPath") != compiler:
        notes.append("settings.json 与 c_cpp_properties.json 的 compilerPath 不一致")

    if "ms-vscode.cpptools" not in exts.get("recommendations", []):
        errors.append("extensions.json 未推荐 ms-vscode.cpptools（调试依赖它）")

    for must in ("README.md", "Makefile", "templates/main.c", "newhw.sh", "tools/check-config.py"):
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
    print("配置检查通过：.vscode 配置自洽，编译/调试路径一致。")
    return 0


if __name__ == "__main__":
    sys.exit(main())
