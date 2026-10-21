#include <stdio.h>
#define max(a, b) (a > b ? (a) : (b))
#define min(a, b) (a < b ? (a) : (b))
int main() {
    int n, tmp, ma = 0, mi = 1000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ma = max(ma, tmp);
        mi = min(mi, tmp);
    }
    printf("%d", ma - mi);
    return 0;
}
