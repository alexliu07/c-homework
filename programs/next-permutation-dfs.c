#include <stdio.h>
#define N 10000
int a[N] = {0}, b[N] = {0};
void sort(int t[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (t[i] > t[j]) {
                int tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}
void copy(int ori[], int dest[], int n) {
    for (int i = 1; i <= n; i++)
        dest[i] = ori[i];
}
int isEqual(int x[], int y[], int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        if (x[i] != y[i]) {
            result = 0;
            break;
        }
    }
    return result;
}
int step[N] = {0}, flag = 0;
void gen(int num[], int n, int total) {
    if (n == 1) {
        step[total] = num[1];
        if (flag == 1) {
            flag = 2;
        } else if (isEqual(step, a, total)) {
            flag = 1;
        }
        return;
    }
    int m = n - 1;
    int tmp[N] = {0};
    for (int i = 1; i <= n; i++) {
        step[total - n + 1] = num[i];
        int k = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            tmp[k] = num[j];
            k++;
        }
        gen(tmp, m, total);
        if (flag == 2)
            break;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    copy(a, b, n);
    sort(b, n);
    gen(b, n, n);
    for (int i = 1; i <= n; i++) {
        printf("%d", step[i]);
        if (i < n)
            printf(" ");
    }
    return 0;
}
