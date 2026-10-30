#include <stdio.h>
#define N 100
#define elif else if
char table[N][N] = {0};
int step[N * N][2] = {0}, vis[N][N] = {0};
int main() {
    int n, m, x, y, sum = 1;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 1; i <= n; i++)
        scanf("%s", table[i] + 1);
    vis[x][y] = 1;
    step[0][0] = x;
    step[0][1] = y;
    while (1) {
        if (table[x - 1][y] == '#' && !vis[x - 1][y])
            x -= 1;
        elif (table[x + 1][y] == '#' && !vis[x + 1][y]) x += 1;
        elif (table[x][y - 1] == '#' && !vis[x][y - 1]) y -= 1;
        elif (table[x][y + 1] == '#' && !vis[x][y + 1]) y += 1;
        else break;
        vis[x][y] = 1;
        step[sum][0] = x;
        step[sum][1] = y;
        sum++;
    }
    printf("%d\n", sum);
    for (int i = 0; i < sum; i++) {
        printf("%d %d\n", step[i][0], step[i][1]);
    }
    return 0;
}
