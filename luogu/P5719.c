#include <stdio.h>
int main() {
    int n, k, a[2] = {0, 0}, b[2] = {0, 0};
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        a[i % k == 0] += i;
        b[i % k == 0]++;
    }
    double r1 = a[0] * 1.0 / b[0], r2 = a[1] * 1.0 / b[1];
    printf("%.1f %.1f", r2, r1);
    return 0;
}
