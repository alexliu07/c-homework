#include <stdio.h>
#define N 101
int box[N][N] = {0}, slimes[N * N][2] = {0};
int main() {
    int n, m, slimesn = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] > 0) {
                slimes[slimesn][0] = i;
                slimes[slimesn][1] = j;
                slimesn++;
            }
        }
    }
    for (int i = 1; i < slimesn; i++) {
        int x = slimes[i][0], y = slimes[i][1];
        if (x - 1 > 0 && box[x - 1][y] < 0) {
            box[x][y] -= box[x - 1][y];
            box[x - 1][y] = 0;
        }
    }
    for (int i = 1; i < slimesn; i++) {
        int x = slimes[i][0], y = slimes[i][1];
        if (y + 1 <= m && box[x][y + 1] < 0) {
            box[x][y] -= box[x][y + 1];
            box[x][y + 1] = 0;
        }
    }
    for (int i = 1; i < slimesn; i++) {
        int x = slimes[i][0], y = slimes[i][1];
        if (x + 1 <= n && box[x + 1][y] < 0) {
            box[x][y] -= box[x + 1][y];
            box[x + 1][y] = 0;
        }
    }
    for (int i = 1; i < slimesn; i++) {
        int x = slimes[i][0], y = slimes[i][1];
        if (y - 1 > 0 && box[x][y - 1] < 0) {
            box[x][y] -= box[x][y - 1];
            box[x][y - 1] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", box[i][j]);
        printf("\n");
    }
    return 0;
}