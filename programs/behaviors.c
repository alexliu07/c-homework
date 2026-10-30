#include <stdio.h>
int ans[19] = {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 16, 0, 18};
int main() {
    int n, tmp, ans1, ans2, ans3;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (i == 0) {
            ans1 = ans[tmp];
            ans2 = ans[tmp];
            ans3 = ans[tmp];
        } else {
            ans1 &= ans[tmp];
            ans2 |= ans[tmp];
            ans3 ^= ans[tmp];
        }
    }
    printf("%d %d %d", ans1, ans2, ans3);
    return 0;
}
