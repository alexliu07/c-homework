#include <stdio.h>
#define swap(a, b)                                                             \
    int t = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = t;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
    int t = gcd(a[0], a[2]);
    printf("%d/%d", a[0] / t, a[2] / t);
    return 0;
}
