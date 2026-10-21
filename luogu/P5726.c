#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int main() {
    int n, tmp, sum = 0, ma = 0, mi = 10;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        sum += tmp;
        ma = max(ma, tmp);
        mi = min(mi, tmp);
    }
    double result = (sum - ma - mi) * 1.0 / (n - 2);
    printf("%.2f", result);
    return 0;
}
