# 大学 C 语言作业仓库

每次 C 语言作业都是一个**单文件**，统一放在 `programs/` 目录下（不套子文件夹），例如
`programs/equation.c`。编辑器配置都在 `.vscode/` 里（随仓库提交）：语言服务用 **clangd**，
调试用 **CodeLLDB**，编译/运行有 VS Code 任务和 Makefile。

## 环境要求

```bash
sudo apt install -y build-essential clangd lldb clang-format   # gcc / clangd / lldb / 格式化
```

VS Code 扩展（已写入 `.vscode/extensions.json`，打开仓库时会提示安装）：

- [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) —— 补全、跳转、诊断
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) —— F5 调试
- 别同时装微软的 C/C++（cpptools）：它和 clangd 会抢语言服务，仓库已把它列入不推荐扩展。

## 目录结构

```
c-homework/
├── .vscode/                 # 编辑器配置都在这里
│   ├── settings.json        #   clangd 参数、缩进编码、clangd 作为 c 的格式化器
│   ├── tasks.json           #   Ctrl+Shift+B 编译当前文件 / 编译全部 / 新建作业
│   ├── launch.json          #   F5 调试（CodeLLDB / lldb）
│   └── extensions.json      #   推荐 clangd + CodeLLDB
├── programs/                # 所有作业，一层平铺
│   └── equation.c
├── templates/main.c         # 新建作业的模板
├── newhw.sh                 # 一键新建作业（./newhw.sh hw02）
├── tools/check-config.py    # 配置自检
├── .clang-format            # 格式化风格
├── Makefile
└── build/                   # 编译产物（gitignore）
```

## 日常使用

### 1. 补全与报错（clangd）

打开 `programs/*.c` 即可：补全、跳转、诊断都由 clangd 提供（参数见 `.vscode/settings.json` 的
`clangd.arguments`）。仓库里没有 `compile_commands.json`，clangd 会用内置默认参数解析单文件作业；
如果日后加了自定义头文件/宏，再生成一份编译数据库即可。

### 2. 编译当前文件

- <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>：编译当前文件 → `build/<文件名>`（`programs/equation.c` → `build/equation`）
- 命令面板 → `Tasks: Run Task` → `gcc: 编译并运行当前文件`：编译后在终端里运行（可输入测试数据）

### 3. 断点调试（F5）

打开任意作业按 <kbd>F5</kbd>，配置名 `调试当前 C 文件 (CodeLLDB / lldb)`：自动先编译再启动 lldb，
断点、单步、查看变量都可用，输入在集成终端里完成。

> clangd 只做语言服务，不管调试；调试由 CodeLLDB 提供。若你更习惯 gdb，也可以装 `gdb` 后把
> `launch.json` 的 `type` 改成 `cppdbg` + `MIMode: gdb`（但那样需要微软 C/C++ 插件）。

### 4. 命令行方式

```bash
make                  # 编译 programs/ 下所有 .c 到 build/
make run HW=equation  # 只编译并运行某个作业（不带 .c 后缀）
make list             # 列出所有产物
make clean            # 删除 build/
```

### 5. 新增作业 / 自检

```bash
./newhw.sh hw02                  # 生成 programs/hw02.c
python3 tools/check-config.py    # 校验 .vscode 配置与 Makefile 是否一致
```

## 库与格式说明

- `math.h` 的 `sqrt` / `pow` 需要链接数学库：Makefile 和编译任务里已经带 `-lm`。
- `scanf` 读 `double` 用 `%lf`，输出用 `%f`。
- 格式化：`clang-format` 已装，风格见 `.clang-format`；`editor.formatOnSave` 默认关闭，
  需要时在 `.vscode/settings.json` 的 `[c]` 里改成 `true`。

## 提交习惯

按功能粒度提交，提交信息用中文：

```bash
git add programs/equation.c
git commit -m "equation: 完成一元三次方程求解"
git push
```

## 其它平台说明

- **Windows (MinGW-w64)**：编译任务用的是 POSIX 写法 `mkdir -p`，在 cmd/PowerShell 下要换成
  `if not exist build mkdir build`（或在 VS Code 里把该任务的默认 shell 设成 Git Bash / WSL）；
  产物加 `.exe` 后缀（`tasks.json` 的输出与 `launch.json` 的 `program` 同步），
  在 `settings.json` 里用 `clangd.path` 指向 Windows 版 `clangd.exe`。
- **macOS**：`brew install llvm` 后把 `clangd.path` 设为 `/opt/homebrew/opt/llvm/bin/clangd`。
- CodeLLDB 自带 lldb，装完扩展即可调试；不需要配 gdb 的 `miDebuggerPath`。
