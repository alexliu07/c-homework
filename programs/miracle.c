#include <stdio.h>
#include <string.h>
#define N 100000
typedef long long ll;
char a[N] = {0};
int num[N] = {0}, numn = 0;
ll getSubSum() {
    ll sum = 0;
    for (int j = 0; j < numn; j++) {
        for (int k = 0; k < numn - j; k++) {
            ll tmp = 0;
            for (int l = k; l <= k + j; l++) {
                tmp *= 10;
                tmp += num[l];
            }
            sum += tmp;
        }
    }
    return sum;
}
ll reverse(ll n) {
    ll result = 0;
    while (n > 0) {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}
int main() {
    while (scanf("%s", a) == 1) {
        int n = strlen(a);
        for (int i = 0; i < n; i++) {
            if ('0' <= a[i] && a[i] <= '9') {
                num[numn] = a[i] - '0';
                numn++;
            } else if (i == 0) {
                printf("%c", a[i]);
            } else if (!('0' <= a[i - 1] && a[i - 1] <= '9')) {
                printf("%c", a[i]);
            } else {
                ll r = reverse(getSubSum());
                printf("%lld%c", r, a[i]);
                numn = 0;
            }
        }
        if ('0' <= a[n - 1] && a[n - 1] <= '9') {
            ll r = reverse(getSubSum());
            printf("%lld", r);
            numn = 0;
        }
        printf("\n");
        memset(a, 0, sizeof(a));
    }
    return 0;
}