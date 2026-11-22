#include <stdio.h>
#include <stdlib.h>
#define N 100000
int g[N] = {0}, s[N] = {0};

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int main() {
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &g[i]);
    if (m > 0) {
        for (int i = 1; i <= m; i++)
            scanf("%d", &s[i]);
        qsort(g, n + 1, sizeof(int), compare_ints);
        qsort(s, m + 1, sizeof(int), compare_ints);
        int i = 1, j = 1;
        while (i <= n && j <= m) {
            if (s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        printf("%d", cnt);
    } else {
        printf("0");
    }
    return 0;
}
