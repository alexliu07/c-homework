#include <stdio.h>
typedef long long ll;
int main() {
    int n, t;
    ll sum = 0;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++) {
        ll tmp = 0;
        for (int j = 1; j <= i; j++) {
            tmp *= 10;
            tmp += t;
        }
        sum += tmp;
    }
    printf("%lld", sum);
    return 0;
}
