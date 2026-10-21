#include <stdio.h>
#include <string.h>
#define N 501
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
int main() {
    int x[N] = {0}, y[N] = {0}, r[N] = {0};
    char a[N], b[N];
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a), m = strlen(b);
    for (int i = 0; i < n; i++)
        x[n - i - 1] = a[i] - 48;
    for (int i = 0; i < m; i++)
        y[m - i - 1] = b[i] - 48;
    int k = plus(x, y, r, n, m);
    int flag = 1;
    for (int i = k - 1; i >= 0; i--) {
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
