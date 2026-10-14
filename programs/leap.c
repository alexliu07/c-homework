#include <stdio.h>
#define ull unsigned long long
int isLeap(ull n) { return (n % 4 == 0 && n % 100 != 0) || n % 400 == 0; }
int main() {
    ull n, k;
    scanf("%llu%llu", &n, &k);
    printf("%s year!\n%s year!", isLeap(n) ? "Leap" : "Normal",
           isLeap(n + k) ? "Leap" : "Normal");
    return 0;
}
