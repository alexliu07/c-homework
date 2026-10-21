#include <stdio.h>
#include <string.h>
#define N 10002
#define max(a, b) ((a) > (b) ? (a) : (b))
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
int sub(int a[], int b[], int r[], int n, int m) {
    int i = 0, t;
    while (i < n || i < m) {
        t = a[i] - b[i] + r[i];
        if (t < 0) {
            r[i + 1]--;
            t += 10;
        }
        r[i] = t;
        i++;
    }
    return n;
}
int multi(int a[], int b[], int r[], int n, int m) {
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t = a[i] * b[j] + r[i + j];
            r[i + j] = t % 10;
            r[i + j + 1] += t / 10;
        }
    }
    return n + m;
}
int isOverEqual(int a[], int b[], int n, int m) {
    int realN = 0, realM = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != 0) {
            realN = i + 1;
            break;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        if (b[i] != 0) {
            realM = i + 1;
            break;
        }
    }
    if (realN > realM)
        return 1;
    if (realN < realM)
        return 0;
    int isOver = 0, isLesser = 0;
    for (int i = realN - 1; i >= 0; i--) {
        if (a[i] > b[i]) {
            isOver = 1;
            break;
        } else if (a[i] < b[i]) {
            isLesser = 1;
            break;
        }
    }
    return !(isOver || isLesser) ? 2 : isOver;
}
int single[N] = {0}, tmp[N], tre[N], rre[N];
int div(int a[], int b[], int r[], int n, int m) {
    single[0] = 1;
    memset(tmp, 0, sizeof(tmp));
    int tbit = 0, rbit = 0;
    while (isOverEqual(tmp, a, tbit, n) == 0) {
        memset(tre, 0, sizeof(tre));
        memset(rre, 0, sizeof(rre));
        tbit = plus(tmp, b, tre, tbit, m);
        for (int i = 0; i < tbit; i++)
            tmp[i] = tre[i];
        rbit = plus(r, single, rre, rbit, 1);
        for (int i = 0; i < rbit; i++)
            r[i] = rre[i];
    }
    memset(rre, 0, sizeof(rre));
    if (isOverEqual(tmp, a, tbit, n) == 1) {
        rbit = sub(r, single, rre, rbit, 1);
        for (int i = 0; i < rbit; i++)
            r[i] = rre[i];
    };
    return rbit;
}
void print(int a[], int n) {
    int flag = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (flag && a[i] == 0 && i > 0)
            continue;
        if (a[i] != 0)
            flag = 0;
        printf("%d", a[i]);
    }
    printf("\n");
}
int a[N], b[N], r[N];
char ta[N], tb[N];
int main() {
    int t;
    char op;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(r, 0, sizeof(r));
        memset(ta, 0, sizeof(ta));
        memset(tb, 0, sizeof(tb));
        scanf("%s %c %s", ta, &op, tb);
        int n = strlen(ta), m = strlen(tb);
        for (int j = 0; j < n; j++)
            a[j] = ta[n - j - 1] - '0';
        for (int j = 0; j < m; j++)
            b[j] = tb[m - j - 1] - '0';
        int x;
        if (op == '+')
            x = plus(a, b, r, n, m);
        else if (op == '-')
            x = sub(a, b, r, n, m);
        else if (op == '*')
            x = multi(a, b, r, n, m);
        else if (op == '/')
            x = div(a, b, r, n, m);
        print(r, x);
    }
    return 0;
}
