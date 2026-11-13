#include <stdio.h>
#define N 5000
#define min(a, b) ((a) < (b) ? (a) : (b))
int a[N] = {0};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    double result = 0;
    int st = 1, ed = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= a[i - 1]) {
            if (st != ed) {
                result = result == 0
                             ? (a[ed] - a[st]) * 1.0 / (ed - st)
                             : min(result, (a[ed] - a[st]) * 1.0 / (ed - st));
            }
            st = i;
        }
        ed = i;
    }
    if (st != ed)
        result = result == 0 ? (a[ed] - a[st]) * 1.0 / (ed - st)
                             : min(result, (a[ed] - a[st]) * 1.0 / (ed - st));
    printf("%.2f", result);
    return 0;
}