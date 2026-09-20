# 大学 C 语言作业仓库

用**单文件**存放每次 C 语言作业（一题一个 `.c` 文件），仓库里已配好 **VS Code 编译 / 运行 / 调试**
全套配置，克隆下来直接按 <kbd>F5</kbd> 调试，不用手工敲 gcc 命令。

## 环境要求

- `gcc`（编译）、`gdb`（调试）、`make`（可选，批量编译）—— Ubuntu/WSL：`sudo apt install -y build-essential gdb`
- VS Code + 扩展 [ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)（打开仓库时会提示安装）

## 目录结构

```
.
├── .vscode/                 # VS Code 配置（随仓库提交，换机器无需重配）
│   ├── tasks.json           #   Ctrl+Shift+B 编译任务
│   ├── launch.json          #   F5 调试（gcc + gdb）
│   ├── c_cpp_properties.json#   IntelliSense / C 标准
│   ├── settings.json        #   缩进、编码、隐藏 build 目录
│   └── extensions.json      #   推荐扩展
├── hw01.c                   # 每次作业一个单文件，直接放仓库根目录
├── templates/main.c         # 新建作业的文件模板
├── newhw.sh                 # 一键新建作业（./newhw.sh hw02）
├── tools/check-config.py    # 自检脚本：校验 VS Code 配置一致性
├── Makefile                 # 批量编译（make / make run HW=hw01）
├── build/                   # 编译产物，已被 .gitignore 忽略
└── README.md
```

## 日常使用

### 1. 编译当前打开的 .c 文件

- <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>：编译当前文件，产物在 `build/<文件名>`
- 命令面板 → `Tasks: Run Task` → `gcc: 编译并运行当前文件`：编译后在终端里直接运行（可以输入测试数据）

### 2. 断点调试

打开任意 `.c` 文件按 <kbd>F5</kbd>（配置名 `调试当前 C 文件 (gcc + gdb)`）：
会自动先编译再启动 gdb，断点、单步、查看变量都能直接用，工作目录是文件所在目录。

### 3. 命令行方式

```bash
make                  # 编译根目录下所有 .c 到 build/
make run HW=hw01      # 只编译并运行 hw01（不要带 .c 后缀）
make list             # 列出所有产物
make clean            # 删除 build/
```

### 4. 新增一次作业

```bash
./newhw.sh hw02        # 生成 hw02.c（含题目注释模板）
```

### 5. 自检配置

改过 `.vscode` 或 `Makefile` 后跑一次，确认编译产物路径、调试入口、任务标签仍然一致：

```bash
python3 tools/check-config.py
```

## 提交习惯

按功能粒度提交，提交信息用中文，例如：

```bash
git add hw02.c
git commit -m "hw02: 完成成绩等级判断"
git push
```

## 其它平台说明

配置按 **Linux（gcc + gdb）** 写好了，换系统改这几处：

- **Windows (MinGW-w64)**：`.vscode/c_cpp_properties.json` 和 `settings.json` 的 `compilerPath`
  改成 `C:/mingw64/bin/gcc.exe`；`tasks.json` 的输出与 `launch.json` 的 `program` 需加 `.exe`；
  输入交互较多时把 `launch.json` 的 `externalConsole` 改成 `true`。
- **macOS**：`brew install gcc gdb`，`compilerPath` 换成 `/opt/homebrew/bin/gcc-14`。
- 若 VS Code 报 `gdb not found`：在 `launch.json` 中加 `"miDebuggerPath": "/usr/bin/gdb"`。
