#include <math.h>
#include <stdio.h>
#define ll long long
int main() {
    ll n,b = 0,sum = 0,p,t;
    scanf("%lld", &n);
    t = n;
    while (t > 0) {
        t /= 10;
        b++;
    }
    t = n;
    while (t > 0) {
        p = t % 10;
        sum += pow(p, b);
        t /= 10;
    }
    printf("%lld", n == sum ? b : 0);
    return 0;
}
