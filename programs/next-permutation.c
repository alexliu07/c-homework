#include <stdio.h>
#define N 10000
#define INF 0x7fffffff
#define min(a, b) (a) < (b) ? (a) : (b)
int a[N] = {0};
void swap(int *p, int *q) {
    int t = *q;
    *q = *p;
    *p = t;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int st;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < a[i + 1]) {
            st = i;
            break;
        }
    }
    int tv = INF, ti;
    for (int i = st + 1; i <= n; i++) {
        if (a[i] > a[st] && a[i] < tv) {
            tv = a[i];
            ti = i;
        }
    }
    swap(&a[st], &a[ti]);
    for (int i = 1; i <= st; i++)
        printf("%d ", a[i]);
    for (int i = n; i > st; i--)
        printf("%d ", a[i]);
    return 0;
}
