#include <stdio.h>
#define N 1000001
#define INF 0x7fffffff
#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)
int a[N] = {0}, b[N] = {0};
int main() {
    int n, m, t, r = INF;
    int amax = 0, amin = INF, bmax = 0, bmin = INF;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        amax = max(amax, a[i]);
        amin = min(amin, a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        bmax = max(bmax, b[i]);
        bmin = min(bmin, b[i]);
    }
    if (amax + bmax <= t)
        r = t - (amax + bmax);
    else if (amin + bmin > t)
        r = -1;
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int tmp = t - (a[i] + b[j]);
                if (tmp >= 0)
                    r = min(r, tmp);
                if (r == 0)
                    break;
            }
        }
    }
    printf("%d", r);
    return 0;
}
