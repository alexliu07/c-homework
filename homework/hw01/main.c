/*
 * hw01 - 求两个整数之和（示例作业，可直接删掉换成真正的第一次作业）
 *
 * 题目：
 *   读入两个整数 a、b，输出它们的和。
 *
 * 样例：
 *   输入: 3 5
 *   输出: 8
 *
 * 调试：
 *   打开本文件按 F5（会先自动编译）；Ctrl+Shift+B 只编译不调试。
 */

#include <stdio.h>

int main(void) {
    int a = 0, b = 0;

    if (scanf("%d %d", &a, &b) != 2) {
        fprintf(stderr, "输入格式错误：需要两个整数\n");
        return 1;
    }

    int sum = a + b;          /* 在这一行打断点，单步看 a / b / sum */
    printf("%d\n", sum);

    return 0;
}
