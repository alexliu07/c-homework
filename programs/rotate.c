#include <stdio.h>
#include <string.h>
#define swap(a, b)                                                             \
    int t = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = t
int main() {
    int a, b, c;
    char op[1001] = {0};
    scanf("%d%d%d%s", &a, &b, &c, op);
    int x1 = 0, x2 = a, y1 = 0, y2 = b;
    int n = strlen(op);
    for (int i = 0; i < n; i++) {
        if (op[i] == 'W') {
            x1 -= c;
            x2 -= a;
            swap(a, c);
        } else if (op[i] == 'S') {
            x1 += c;
            x2 += a;
            swap(a, c);
        } else if (op[i] == 'A') {
            y1 -= c;
            y2 -= b;
            swap(b, c);
        } else {
            y1 += c;
            y2 += b;
            swap(b, c);
        }
    }
    printf("%d %d %d %d", x1, x2, y1, y2);
    return 0;
}