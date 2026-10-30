// 本题无英文名，标题为a + b problem EX
#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 100000
int plus(int a[], int b[], int r[], int n, int m) {
    int i = 0, t;
    while (i < n || i < m) {
        t = a[i] + b[i] + r[i];
        r[i] = t % 10;
        r[i + 1] += t / 10;
        i++;
    }
    return max(n, m) + 1;
}
int a[N], b[N], r[N];
char line[N], x[N], y[N];
int main() {
    int n, m, bts, flag;
    while (fgets(line, sizeof(line), stdin)) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(r, 0, sizeof(r));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        sscanf(line, "%s%s", x, y);
        n = strlen(x);
        m = strlen(y);
        for (int i = 0; i < n; i++)
            a[n - i - 1] = x[i] - '0';
        for (int i = 0; i < m; i++)
            b[m - i - 1] = y[i] - '0';
        bts = plus(a, b, r, n, m);
        flag = 1;
        for (int i = bts - 1; i >= 0; i--) {
            if (flag && r[i] == 0 && i > 0)
                continue;
            if (r[i] != 0)
                flag = 0;
            printf("%d", r[i]);
        }
        printf("\n");
        memset(line, 0, sizeof(line));
    }
    return 0;
}
