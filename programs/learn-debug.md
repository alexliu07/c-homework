# 认识断点调试

- **竞赛**：0-intro-run-debug
- **题目 ID**：253
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：[https://public.oj.cpl.icu/contest/3/problem/253](https://public.oj.cpl.icu/contest/3/problem/253)

## 题目描述

调试器可以让程序在指定位置暂停，查看变量的当前值。请先完成上一题，确认能够在本地运行 C 程序，再用同一套环境完成本题的断点调试。

> 使用 Dev-C++、Visual Studio 等其他 IDE 的同学，也可以用自己的工具完成本题。请自行查阅对应工具的说明，了解如何编译、运行和调试 C 程序，包括设置断点、查看变量和继续执行。Visual Studio 与 VS Code 是不同的软件。

### 准备调试

#### CLion

按 [CLion 指南](https://njusecourse.feishu.cn/wiki/IGaswcsHGiKs2qksdRqcGRxqnte)新建一个 C 项目，用下面的完整代码替换 `main.c` 中的内容。**不要将上一题的程序和本题的程序放在一起编译。**

完成下面操作步骤的第 1、2 步后，找到右上角的**小瓢虫图标🐞**，或者点击 `main` 函数行号旁的绿色小三角，在弹出的菜单中选择带**小瓢虫图标🐞的「Debug/调试」**。

它就在上一题使用的「Run」下面。下图从课程讲义中截取，`hello` 会替换为你自己的项目名。

<img src="https://public.oj.cpl.icu/image/clion-debug.jpg.6689ee3a" alt="CLion：选择小虫图标旁的 Debug 菜单项" width="420">

#### VS Code

将下面的代码保存为 `local_debug.c`。打开 [VS Code 指南第 8 节「调试程序」](https://njusecourse.feishu.cn/wiki/IkDsw9D9WiegBykmygOcF6QLnah#XKB0dVJLgoQDR4xZ7Y2cu1X8n9g)：上一题使用 Code Runner 的同学先看 8.1，使用终端命令的同学先看 8.2；再按 8.4 的截图配置调试。这些设置让调试器能够找到源码并显示变量的值，跟着讲义操作即可。

设置断点后，点击左侧「运行和调试」图标，再点击「Run and Debug／运行和调试」按钮。不要只点击 Code Runner 的「Run Code」，它会直接运行程序，不会在断点暂停。下图取自课程讲义。

<img src="https://public.oj.cpl.icu/image/vscode-debug-start.jpg.68bdff45" alt="VS Code：运行和调试侧栏及 Run and Debug 按钮" width="400">

### 操作步骤

1. 将 `STUDENT_ID` 后双引号内的 `YOUR_STUDENT_ID` 改成自己的学号，保留双引号；没有学号的同学填写自己的 OJ 账号。保存文件。
2. 在第 **62 行**，即包含 `BREAKPOINT: inspect debug_value, then continue.` 的 `printf` 语句的行号左侧点击，出现断点标记即可。请以该语句为准；如果你调整过空行，行号可能变化。
3. 使用「调试」功能启动程序。程序停在断点后，在变量或监视窗口中查看 `debug_value`，可能需要添加**监视变量** `debug_value` 才能在调试中看到它，记下它的**十进制九位整数值**。
4. 点击「Resume／继续」。出现 `Enter debug_value in decimal:` 时，在**程序的输入输出窗口**输入刚才看到的值并回车。CLion 使用程序的 Console（控制台），VS Code 使用运行程序的终端或弹出的控制台，不要把这个值输入用于执行调试命令的 Debug Console。
5. 完整复制程序生成的、以 `CPL26.` 开头的一行报告，粘贴到本题右侧的「测试输入」中，然后点击「提交测试输入」。

报告和观察值通过检查后，本题通过。每次重新运行时，观察值都可能变化，请使用本次运行中看到的值。

命中断点后，当前语句会高亮；观察完变量后，点击浮动工具栏的第一个三角形按钮继续执行。下图演示的是讲义中的 Hello, World!，本题应停在第 62 行的断点语句。

<img src="https://public.oj.cpl.icu/image/vscode-debug-paused.jpg.6534f0f3" alt="VS Code：断点命中时的高亮语句，以及上方工具栏的继续按钮" width="540">

如果程序没有在断点暂停，先确认文件已经保存，断点标记仍在，并且点击的是「调试」按钮。如果找不到变量或仍无法暂停，请带上电脑和报错截图，按本次作业说明参加机房实验课或线下答疑。

### 本地程序

请完整复制以下代码。学号填写处和 `main` 函数中的断点语句是本题的操作位置。

你可以选择不填写自己的学号，或者请别人帮你运行，但本题会根据提交的报告进行分析与查重。

若被查到不是你本人运行得出的结果，则本题不计入平时分通过数，并且会收到助教警告。

```c:linenums
#define _CRT_SECURE_NO_WARNINGS
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 【请填写】将 YOUR_STUDENT_ID 改为你的学号，保留双引号。
 * 没有学号的同学填写自己的 OJ 账号；其余配置保持不变。
 */
#define STUDENT_ID "YOUR_STUDENT_ID"
#define DEBUG_TASK 1

static int account_ok(void);
static int environment_id(char id[33]);
static void compiler_name(char name[64]);
static const char *os_name(void);
static uint32_t checksum(const char *text);
static uint32_t observation(const char *text);
static void print_base64(const char *text);

int main(void) {
    char environment[33] = {0};
    char compiler[64] = {0};
    char report[1024] = {0};
    const time_t now = time(NULL);

    if (!account_ok()) {
        printf("Please set STUDENT_ID to your own student ID.\n");
        return 1;
    }
    if (now < 0 || (uint64_t)now > UINT64_C(4102444800)) {
        printf("Please check your system clock.\n");
        return 1;
    }
    if (!environment_id(environment)) {
        printf("Cannot read or write cpl26-environment.txt.\n");
        printf("Use a writable folder and check this file.\n");
        return 1;
    }

    compiler_name(compiler);
    const int length = snprintf(
        report, sizeof(report),
        "CPL26-HW0\ntask=%s\naccount=%s\nenv=%s\nos=%s\ncompiler=%s\n"
        "time=%" PRId64 "\npointer_bits=%u\n",
        DEBUG_TASK ? "debug" : "run", STUDENT_ID, environment,
        os_name(), compiler, (int64_t)now,
        (unsigned int)(sizeof(void *) * 8)
    );
    if (length < 0 || (size_t)length >= sizeof(report) - 64) {
        printf("The report is too long.\n");
        return 1;
    }

    /* 调试题：在下一条 printf 处暂停，观察本次运行的 debug_value。 */
    volatile uint32_t debug_value = observation(report);
    uint32_t answer = debug_value;
    if (DEBUG_TASK) {
        /* ↓ */
        printf("BREAKPOINT: inspect debug_value, then continue.\n");
        /* ↑ */
        printf("Enter debug_value in decimal: ");
        fflush(stdout);

        char answer_text[32] = {0};
        if (scanf("%31s", answer_text) != 1 || strlen(answer_text) != 9 ||
            strspn(answer_text, "0123456789") != 9 || answer_text[0] == '0') {
            printf("Enter the nine-digit value shown by your debugger.\n");
            return 1;
        }
        answer = (uint32_t)strtoul(answer_text, NULL, 10);
    }

    snprintf(report + length, sizeof(report) - (size_t)length,
             "value=%" PRIu32 "\n", answer);
    const size_t payload_length = strlen(report);
    const uint32_t check = checksum(report);
    snprintf(report + payload_length, sizeof(report) - payload_length,
             "checksum=%08" PRIX32 "\n", check);

    printf("Copy the following CPL26. line into the OJ test input:\n");
    print_base64(report);
    return 0;
}

/* ===================================================================
 * 以下函数负责整理和编码报告，本次练习不需要阅读或修改。
 * =================================================================== */

static uint32_t checksum(const char *text) {
    uint32_t result = UINT32_C(2166136261);
    while (*text != '\0') {
        result = (result ^ (unsigned char)*text++) * UINT32_C(16777619);
    }
    return result;
}

static uint32_t observation(const char *text) {
    uint32_t result = checksum(text);
    for (int i = 0; i < 6; ++i) {
        result = result * UINT32_C(1664525) + UINT32_C(1013904223);
    }
    return result % UINT32_C(900000000) + UINT32_C(100000000);
}

static int account_ok(void) {
    const char *account = STUDENT_ID;
    const size_t length = strlen(account);
    if (length == 0 || length > 64 || strcmp(account, "YOUR_STUDENT_ID") == 0) {
        return 0;
    }
    for (size_t i = 0; i < length; ++i) {
        const unsigned char c = (unsigned char)account[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') || strchr("._@-", c) != NULL)) {
            return 0;
        }
    }
    return 1;
}

static int environment_id(char id[33]) {
    static const char digits[] = "0123456789abcdef";
    const char *path = "cpl26-environment.txt";
    FILE *file = fopen(path, "r");
    if (file != NULL) {
        char line[64] = {0};
        const int read_ok = fgets(line, sizeof(line), file) != NULL;
        fclose(file);
        if (!read_ok) {
            return 0;
        }
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) != 32 || strspn(line, digits) != 32 ||
            strcmp(line, "00000000000000000000000000000000") == 0 ||
            strcmp(line, "ffffffffffffffffffffffffffffffff") == 0) {
            return 0;
        }
        memcpy(id, line, 33);
        return 1;
    }
    srand((unsigned int)time(NULL) ^ (unsigned int)clock() ^ checksum(STUDENT_ID));
    for (int i = 0; i < 32; ++i) {
        id[i] = digits[(unsigned int)rand() % 16];
    }
    id[32] = '\0';
    if (strspn(id, "0") == 32 || strspn(id, "f") == 32) {
        id[0] = '1';
    }
    file = fopen(path, "w");
    if (file == NULL) {
        return 0;
    }
    const int saved = fprintf(file, "%s\n", id) > 0;
    return fclose(file) == 0 && saved;
}

static void compiler_name(char name[64]) {
#if defined(__clang__)
    snprintf(name, 64, "Clang-%d.%d.%d",
             __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__)
    snprintf(name, 64, "GCC-%d.%d.%d",
             __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
    snprintf(name, 64, "MSVC-%d", _MSC_VER);
#else
    snprintf(name, 64, "Other");
#endif
}

static const char *os_name(void) {
#if defined(_WIN32)
    return "Windows";
#elif defined(__APPLE__)
    return "macOS";
#elif defined(__linux__)
    return "Linux";
#else
    return "Other";
#endif
}

static void print_base64(const char *text) {
    static const char digits[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const size_t length = strlen(text);
    printf("CPL26.");
    for (size_t i = 0; i < length; i += 3) {
        const size_t remain = length - i;
        uint32_t block = (uint32_t)(unsigned char)text[i] << 16;
        if (remain > 1) {
            block |= (uint32_t)(unsigned char)text[i + 1] << 8;
        }
        if (remain > 2) {
            block |= (unsigned char)text[i + 2];
        }
        printf("%c%c%c%c",
               digits[(block >> 18) & 63], digits[(block >> 12) & 63],
               remain > 1 ? digits[(block >> 6) & 63] : '=',
               remain > 2 ? digits[block & 63] : '=');
    }
    printf("\n");
}
```

## 输入格式

提交本地程序生成的一行报告，以 `CPL26.` 开头，后面是 Base64 编码的文本。

每次提交只需一份输入，最多 2048 字节。

**不要同时粘贴终端提示语。**

## 输出格式

报告格式和校验结果正确时，即可通过本题。

## 提示

### 报告包含什么

报告包含你填写的学号（没有学号时填写的 OJ 账号）、编译器版本、系统类型、程序位数、运行时间、随机环境标识和校验值，供助教核对练习情况。Base64 用于将报告整理成便于复制的一行文本。

程序会在运行目录中生成 `cpl26-environment.txt`，保存随机环境标识。请保留这个小文件，后续运行会继续使用它。如果程序提示无法读写该文件，请把源码和可执行程序放到你有读写权限的文件夹中再运行。
