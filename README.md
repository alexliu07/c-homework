# 大学 C 语言作业仓库

存放大学《C 语言程序设计》课程作业的代码，仓库内已配好 **VS Code 编译 / 运行 / 调试** 全套配置，
克隆下来即可按 <kbd>F5</kbd> 调试，不需要再手工敲 gcc 命令。

## 环境要求

| 工具 | 用途 | 检查命令 |
| --- | --- | --- |
| gcc | 编译 C 代码 | `gcc --version` |
| gdb | 断点调试（VS Code 的 cppdbg 依赖） | `gdb --version` |
| make | 一键编译整个仓库（可选） | `make --version` |
| VS Code + 扩展 [ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) | 语法提示与调试 | 打开仓库后会提示安装 |

Ubuntu / WSL 安装：

```bash
sudo apt install -y build-essential gdb
```

## 目录结构

```
.
├── .vscode/                 # VS Code 配置（随仓库提交，换机器无需重配）
│   ├── tasks.json           #   Ctrl+Shift+B 编译任务
│   ├── launch.json          #   F5 调试（gcc + gdb）
│   ├── c_cpp_properties.json#   IntelliSense 头文件路径 / C 标准
│   ├── settings.json        #   缩进、编码、隐藏 build 目录
│   └── extensions.json      #   推荐扩展
├── homework/                # 每次作业一个子目录
│   └── hw01/                #   示例作业：求两个整数之和
│       ├── main.c
│       └── README.md        #   作业题目 / 思路 / 完成情况
├── templates/main.c         # 新建作业的文件模板
├── tools/check-config.py    # 自检脚本：校验 VS Code 配置一致性
├── newhw.sh                 # 一键新建一次作业
├── Makefile
└── build/                   # 编译产物（已被 .gitignore 忽略）
```

## 日常使用

### 1. 编译并运行当前打开的 .c 文件

- <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>：编译当前文件 → 产物在 `build/<相对路径>/<文件名>`
- <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> → `Tasks: Run Task` → `gcc: 编译并运行当前文件`

### 2. 断点调试

打开任意 `homework/**/*.c`，按 <kbd>F5</kbd>（选 `调试当前 C 文件 (gcc + gdb)`）。
它会在调试前自动用 gcc 编译当前文件，断点 / 单步 / 查看变量都可直接用。
工作目录是当前文件所在目录，程序里用相对路径读写文件时不用改 cwd。

### 3. 命令行方式

```bash
make                  # 编译所有作业（每个 homework/<hw> 目录编译成一个可执行文件）
make run HW=hw01      # 编译并运行 hw01
make list             # 列出所有会生成的产物
make clean            # 删除 build/
```

### 4. 新增一次作业

```bash
./newhw.sh hw03         # 生成 homework/hw03/{main.c,README.md}
./newhw.sh hw03-圆面积   # 也可以带中文说明，只影响目录名与注释
```

## 提交习惯

按功能粒度提交，提交信息用中文，例如：

```bash
git add homework/hw03
git commit -m "hw03: 完成圆的面积计算"
git push
```

## 其他平台说明

配置默认按 **Linux (gcc 13 / gdb)** 写好，在别的系统上跑请改两处：

- **Windows (MinGW-w64)**：把 `.vscode/c_cpp_properties.json` 与 `settings.json` 里的
  `compilerPath` / `C_Cpp.default.compilerPath` 改成 `C:/mingw64/bin/gcc.exe`；
  `launch.json` 的 `program` 与 `tasks.json` 输出要加 `.exe` 后缀；
  `externalConsole` 建议改成 `true` 方便输入。
- **macOS**：`brew install gcc gdb`（或用系统 clang），把 `compilerPath` 换成
  `/opt/homebrew/bin/gcc-14`，`miDebuggerPath`（如需要）指向 `/opt/homebrew/bin/gdb`。
- 如果 VS Code 报 `gdb not found`，在 `launch.json` 里加上
  `"miDebuggerPath": "/usr/bin/gdb"`。
