#include <stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a & b);
    printf("%d\n", a | b);
    printf("%d\n", a ^ b);
    printf("%d\n", ~a);
    printf("%d\n", a << b);
    printf("%d\n", a >> b);
    int i = 0, sum = 0;
    while (a > 0) {
        sum += a % 2;
        if (i == b)
            printf("%d\n", a % 2);
        a /= 2;
        i++;
    }
    if (i <= b)
        printf("0\n");
    printf("%d", sum);
    return 0;
}
