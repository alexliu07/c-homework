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
#define STUDENT_ID "261180197"
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