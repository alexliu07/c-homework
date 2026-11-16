#include <stdio.h>
int a[13] = {0, -1, -2, -3, -4, -5, -6, -7, 8, 9, -10, 11, 12};
int main() {
    int n, tmp;
    int ans1, ans2, ans3;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        if (i == 1) {
            ans1 = a[tmp];
            ans2 = a[tmp];
            ans3 = a[tmp];
        } else {
            ans1 &= a[tmp];
            ans2 |= a[tmp];
            ans3 ^= a[tmp];
        }
    }
    printf("%d %d %d", ans1, ans2, ans3);
    return 0;
}