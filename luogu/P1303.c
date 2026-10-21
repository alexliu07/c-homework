#include <stdio.h>
#include <string.h>
#define N 10000
char p[N] = {0}, q[N] = {0};
int a[N] = {0}, b[N] = {0}, r[N] = {0};
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
int main() {
    scanf("%s", p);
    scanf("%s", q);
    int n = strlen(p);
    int m = strlen(q);
    for (int i = 0; i < n; i++)
        a[n - i - 1] = p[i] - 48;
    for (int i = 0; i < m; i++)
        b[m - i - 1] = q[i] - 48;
    int x = multi(a, b, r, n, m);
    int flag = 1;
    for (int i = x - 1; i >= 0; i--) {
        if (i == 0)
            flag = 0;
        if (r[i] != 0)
            flag = 0;
        if (flag && r[i] == 0)
            continue;
        printf("%d", r[i]);
    }
    return 0;
}
