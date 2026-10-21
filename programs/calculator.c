#include <math.h>
#include <stdio.h>
#include <string.h>
#define elif else if
int main() {
    int a, b;
    char line[100] = {0}, op[10] = {0};
    while (fgets(line, sizeof(line), stdin)) {
        sscanf(line, "%d %s %d", &a, op, &b);
        if (op[0] == '+')
            printf("%d", a + b);
        elif (op[0] == '-') printf("%d", a - b);
        elif (op[0] == '*') {
            if (op[1] == '*')
                printf("%.0f", pow(a, b));
            else
                printf("%d", a * b);
        }
        elif (op[0] == '/') {
            if (op[1] == '*')
                printf("%.3f", a * 1.0 / b);
            else
                printf("%d", a / b);
        }
        elif (op[0] == '%') printf("%d", a % b);
        printf("\n");
        memset(line, 0, sizeof(line));
        memset(op, 0, sizeof(op));
    }
    return 0;
}
