#include <stdio.h>
#define INF 0x7fffffff
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int table[81][301] = {0};
int main() {
    int n, m, k, slime = 0, total = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &table[i][j]);
            if (table[i][j] > 0)
                slime++;
            total += table[i][j];
        }
    }
    if (slime == 0)
        printf("0");
    else if (k == 1) {
        int C = INF;
        for (int i = 1; i < n; i++) {
            int up = 0, down = 0;
            for (int j = 1; j <= i; j++) {
                for (int k = 1; k <= m; k++) {
                    up += table[j][k];
                }
            }
            for (int j = i + 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    down += table[j][k];
                }
            }
            C = min(C, max(up, down));
        }
        printf("%d", C);
    } else {
        int st = 0, ed = total, C = (st + ed) / 2;
        while (ed - st > 1) {
            int f = 0;
            for (int i = 1; i < n; i++) {
                int flag = 0;
                int tup = 0, tdown = 0, lines = 0;
                for (int j = 1; j <= m; j++) {
                    int up = 0, down = 0;
                    for (int k = 1; k <= i; k++) {
                        up += table[k][j];
                    }
                    for (int k = i + 1; k <= n; k++) {
                        down += table[k][j];
                    }
                    if (up > C || down > C) {
                        flag = 1;
                        break;
                    }
                    tup += up;
                    tdown += down;
                    if (tup > C || tdown > C) {
                        lines++;
                        tup = up;
                        tdown = down;
                    }
                }
                if (flag)
                    continue;
                if (lines <= k - 1) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                ed = C;
            } else {
                st = C;
            }
            C = (st + ed) / 2;
        }
        printf("%d", ed);
    }
    return 0;
}