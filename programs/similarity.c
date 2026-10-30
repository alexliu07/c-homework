#include <stdio.h>
#define N 101
int table[N][N] = {0};
int main() {
    int n, m, tmp, sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &tmp);
            sum += tmp == table[i][j];
        }
    }
    printf("%.2f", sum * 100.0 / (n * m));
    return 0;
}
