#include <stdio.h>
#define elif else if
#define N 0xffffffffLL
typedef long long ll;
int main() {
    ll n = N / 2, st = 0, ed = N + 1;
    char res[10];
    while (1) {
        printf("%lld\n", n);
        fflush(stdout);
        scanf("%s", res);
        if (res[0] == 'G')
            ed = n;
        elif (res[0] == 'L') st = n;
        elif (res[0] == 'E' || res[0] == 'O') break;
        n = (ed + st) / 2;
    }
    return 0;
}
