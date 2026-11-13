# 初试本地运行

- **竞赛**：0-intro-run-debug
- **题目 ID**：252
- **时间限制**：1000 ms ｜ **内存限制**：256000 KiB
- **原题链接**：[https://public.oj.cpl.icu/contest/3/problem/252](https://public.oj.cpl.icu/contest/3/problem/252)

## 题目描述

请先按照课程讲义[《开学第 0 课：准备开发环境》](https://njusecourse.feishu.cn/wiki/PQJ2wsluAimTgSk2Ql1c9UEFn4e)，在自己的电脑上配置 CLion 或 VS Code，并运行讲义中的 Hello, World! 程序，再完成本题。

讲义提供了 [CLion 配置指南](https://njusecourse.feishu.cn/wiki/IGaswcsHGiKs2qksdRqcGRxqnte)和 [VS Code 配置指南](https://njusecourse.feishu.cn/wiki/IkDsw9D9WiegBykmygOcF6QLnah)，选择与你使用的工具对应的章节即可。

> 使用 Dev-C++、Visual Studio 等其他 IDE 的同学，也可以用自己的工具完成本题。请自行查阅对应工具的说明，了解如何编译和运行 C 程序。Visual Studio 与 VS Code 是不同的软件。

### 操作步骤

1. 复制下面的完整程序。使用 CLion 时，可以按讲义创建一个独立的 C 项目，用本题代码替换自动生成的 `main.c`；使用 VS Code 时，在已配置好的工作文件夹中保存为 `local_run.c`。
2. 将 `STUDENT_ID` 后双引号内的 `YOUR_STUDENT_ID` 改成自己的学号，保留双引号。没有学号的同学填写自己的 OJ 账号。保存文件后，按照讲义运行程序：CLion 使用当前项目的「Run／运行」，VS Code 可以使用讲义中的 Code Runner 或终端方式。
3. 程序会输出一行以 `CPL26.` 开头的报告。完整复制这一行，在本题右侧的「测试输入」中粘贴，然后点击「提交测试输入」。只保留一份输入，不需要提交源码或填写预期输出。

报告通过检查后，本题通过。若提示输入不合法，请展开提交详情查看原因，再检查学号填写和复制是否完整。

下面是课程讲义中的 CLion 运行菜单。点击代码左侧的绿色三角，再选择第一项「Run」。图中的 `hello` 是讲义的项目名，你的菜单会显示自己的项目名。

<img src="https://public.oj.cpl.icu/image/clion-run.png.422a4209" alt="CLion：绿色三角菜单中的 Run 运行入口" width="460">

使用 VS Code 的同学，按 [Code Runner 运行步骤](https://njusecourse.feishu.cn/wiki/IkDsw9D9WiegBykmygOcF6QLnah#Odvcdh6CnoppGzxRrkOcS1Uunle)操作即可。

完成本题后，保留配置好的开发环境。下一题会继续使用它，但需要启动「调试」，仅使用 Code Runner 运行程序还不能完成断点练习。

### 本地程序

请完整复制以下代码。需要填写学号的位置在开头，之后的 `main` 函数等代码都不需要修改。

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
#define DEBUG_TASK 0

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
        printf("BREAKPOINT: inspect debug_value, then continue.\n");
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
