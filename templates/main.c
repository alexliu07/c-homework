/*
 * __HW_NAME__ - 大学 C 语言作业
 *
 * 题目：
 *   在这里写题目描述
 *
 * 说明：
 *   按 Ctrl+Shift+B 编译当前文件，按 F5 进入 gdb 调试。
 */

#include <stdio.h>

int main(void) {
    /* TODO: 在这里写你的代码 */

    int a = 0, b = 0;
    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "输入格式错误：需要两个整数\n");
        return 1;
    }

    printf("%d\n", a + b);
    return 0;
}
