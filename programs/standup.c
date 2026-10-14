#include <stdio.h>
#define N 100000
int a[N];
int main() {
    int n, cur, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &a[i]);
    }
    cur = a[0];
    for (int i = 1; i <= n; i++) {
        if (cur < i) {
            r += i - cur;
            cur = i;
        }
        cur += a[i];
    }
    printf("%d", r);
    return 0;
}
