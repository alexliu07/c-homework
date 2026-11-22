#include <stdio.h>
#define N 100
int table[N][N] = {0};
int lists[N * N] = {0};

int main() {
    int n, m = 1;
    scanf("%d\n", &n);
    char line[N] = {0};
    for (int i = 1; i <= n; i++) {
        if (m == 1) {
            fgets(line, sizeof(line), stdin);
            while (sscanf(line + (m - 1) * 2, "%d", &table[i][m]) != -1) {
                m++;
            }
            m--;
        } else {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &table[i][j]);
            }
        }
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i < n && table[i][j] != table[i + 1][j]) ||
                (j < m && table[i][j] == table[i][j + 1])) {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    if (flag)
        printf("true");
    else
        printf("false");
    return 0;
}
