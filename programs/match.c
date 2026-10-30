#include <stdio.h>
#define N 501
int table[N][N] = {0}, pos[N * N / 2][2][2] = {0};
int isVertical(int a, int b, int x, int y, int n) {
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    for (int i = a - 1; i > 0; i--) {
        if (table[i][b] != 0) {
            flag1 = 1;
            break;
        }
    }
    for (int i = x - 1; i > 0; i--) {
        if (table[i][y] != 0) {
            flag2 = 1;
            break;
        }
    }
    for (int i = a + 1; i <= n; i++) {
        if (table[i][b] != 0) {
            flag3 = 1;
            break;
        }
    }
    for (int i = x + 1; i <= n; i++) {
        if (table[i][y] != 0) {
            flag4 = 1;
            break;
        }
    }
    return !(flag1 || flag2) || !(flag3 || flag4);
}
int isHorizontal(int a, int b, int x, int y, int m) {
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    for (int i = b - 1; i > 0; i--) {
        if (table[a][i] != 0) {
            flag1 = 1;
            break;
        }
    }
    for (int i = y - 1; i > 0; i--) {
        if (table[x][i] != 0) {
            flag2 = 1;
            break;
        }
    }
    for (int i = b + 1; i <= m; i++) {
        if (table[a][i] != 0) {
            flag3 = 1;
            break;
        }
    }
    for (int i = y + 1; i <= m; i++) {
        if (table[x][i] != 0) {
            flag4 = 1;
            break;
        }
    }
    return !(flag1 || flag2) || !(flag3 || flag4);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &table[i][j]);
            if (pos[table[i][j]][0][0] != 0 && pos[table[i][j]][0][1] != 0) {
                pos[table[i][j]][1][0] = i;
                pos[table[i][j]][1][1] = j;
            } else {
                pos[table[i][j]][0][0] = i;
                pos[table[i][j]][0][1] = j;
            }
        }
    }
    for (int i = 1; i <= n * m / 2; i++) {
        if (isVertical(pos[i][0][0], pos[i][0][1], pos[i][1][0], pos[i][1][1],
                       n) ||
            isHorizontal(pos[i][0][0], pos[i][0][1], pos[i][1][0], pos[i][1][1],
                         m)) {
            printf("%d ", i);
            table[pos[i][0][0]][pos[i][0][1]] = 0;
            table[pos[i][1][0]][pos[i][1][1]] = 0;
        }
    }
    return 0;
}
