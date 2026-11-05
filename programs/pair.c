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
        for (int j = 1; j <= m; j++) {
            int st = 0, ed = n + 1, flag = 0;
            int i = (st + ed) / 2;
            while (ed - st > 1) {
                if (a[i] + b[j] == t) {
                    flag = 1;
                    break;
                } else if (a[i] + b[j] < t)
                    st = i;
                else
                    ed = i;
                i = (st + ed) / 2;
            }
            if (flag) {
                r = 0;
                break;
            }
            int a1 = a[st] + b[j];
            int a2 = a[ed] + b[j];
            int tmp = max(a1 <= t ? a1 : -1, a2 <= t ? a2 : -1);
            r = min(r, t - tmp);
        }
    }
    printf("%d", r);
    return 0;
}
