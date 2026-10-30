#include <stdio.h>
#define N 1000
int table[N][N] = {0};
int main() {
    int n;
    scanf("%d", &n);
    int pos[2] = {0}, tmp[2] = {0};
    pos[0] = 0;
    pos[1] = (n + 1) / 2 - 1;
    table[pos[0]][pos[1]] = 1;
    for (int i = 2; i <= n * n; i++) {
        tmp[0] = (pos[0] - 1 + n) % n;
        tmp[1] = (pos[1] + 1 + n) % n;
        if (table[tmp[0]][tmp[1]] == 0) {
            pos[0] = tmp[0];
            pos[1] = tmp[1];
        } else
            pos[0] = (pos[0] + 1) % n;
        table[pos[0]][pos[1]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
