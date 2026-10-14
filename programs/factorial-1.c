#include <stdio.h>
#define MOD 10007
#define ll long long
int main() {
    ll n, cur = 1, sum = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        cur *= i;
        cur %= MOD;
        sum += cur;
        sum %= MOD;
    }
    printf("%lld", sum);
    return 0;
}
