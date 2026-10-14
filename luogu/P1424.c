#include <stdio.h>
int main() {
    int x, n, r = 0, t;
    scanf("%d%d", &x, &n);
    for (int i = x; i < x + n; i++) {
        t = i % 7;
        r += t == 0 || t == 6 ? 0 : 250;
    }
    printf("%d", r);
    return 0;
}
