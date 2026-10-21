#include <stdio.h>
#define N 100
int max(int a, int b) { return a > b ? a : b; }
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
int multi(int a[], int b[], int r[], int n, int m) {
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t = a[i] * b[j] + r[j + i];
            r[j + i] = t % 10;
            r[j + i + 1] += t / 10;
        }
    }
    return n + m;
}
int cur[N] = {0}, res[N] = {0}, sum[N] = {0}, re[N] = {0};
int main() {
    int n, x = 1, y, tmp[2], z = 1;
    cur[0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        y = (i >= 10) + 1;
        tmp[0] = i % 10;
        tmp[1] = i / 10;
        x = multi(cur, tmp, res, x, y);
        for (int j = 0; j < x; j++) {
            cur[j] = res[j];
            res[j] = 0;
        }
        z = plus(sum, cur, re, z, x);
        for (int j = 0; j < z; j++) {
            sum[j] = re[j];
            re[j] = 0;
        }
    }
    int flag = 1;
    for (int i = z - 1; i >= 0; i--) {
        if (i == 0)
            flag = 0;
        if (sum[i] != 0)
            flag = 0;
        if (flag && sum[i] == 0)
            continue;
        printf("%d", sum[i]);
    }
    return 0;
}
