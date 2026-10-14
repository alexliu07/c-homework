#include <stdio.h>
#define N 501
int plus(int a[], int b[], int r[], int n, int m) {
    int i = 0, t;
    while (i < n || i < m) {
        t = a[i] + b[i] + r[i];
        r[i] = t % 10;
        r[i + 1] += t / 10;
        i++;
    }
    return i + 1;
}
int main() {
    int n = 0, m = 0, x[N] = {0}, y[N] = {0}, r[N] = {0};
    char a[N], b[N];
    while (1) {
        scanf("%c", &a[n]);
        if (a[n] == 0 || a[n] == '\n')
            break;
        n++;
    }
    while (1) {
        scanf("%c", &b[m]);
        if (b[m] == 0 || b[m] == '\n')
            break;
        m++;
    }
    for (int i = 0; i < n; i++)
        x[n - i - 1] = a[i] - 48;
    for (int i = 0; i < m; i++)
        y[m - i - 1] = b[i] - 48;
    int k = plus(x, y, r, n, m);
    for (int i = k - 1; i >= 0; i--) {
        if (i == k - 1 && r[i] == 0)
            continue;
        printf("%d", r[i]);
    }
    return 0;
}
