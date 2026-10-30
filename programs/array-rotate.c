// 本题无英文名，标题为魔方预备题（数组旋转）
#include <stdio.h>
#define N 1000
int table[N][N] = {0};
int main() {
    int n;
    char op[20] = {0};
    scanf("%s%d", op, &n);
    for (int i = 0; i < 6 * n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    if (op[0] == 'r') {
        int side;
        scanf("%d", &side);
        for (int i = 0; i < side * n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", table[i][j]);
            printf("\n");
        }
        for (int i = 0; i < n; i++) {
            for (int j = side * n + (n - 1); j >= side * n; j--)
                printf("%d ", table[j][i]);
            printf("\n");
        }
        for (int i = (side + 1) * n; i < 6 * n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", table[i][j]);
            printf("\n");
        }
    } else {
        int s[4], l[4];
        for (int i = 0; i < 4; i++) {
            scanf("%d%d", &s[i], &l[i]);
        }
        for (int i = 0; i < 6 * n; i++) {
            int change = -1;
            for (int j = 0; j < 4; j++) {
                if (i == n * s[j] + l[j]) {
                    change = j;
                    break;
                }
            }
            if (change == -1)
                for (int j = 0; j < n; j++)
                    printf("%d ", table[i][j]);
            else
                for (int j = 0; j < n; j++)
                    printf("%d ", table[n * s[(change + 3) % 4] +
                                        l[(change + 3) % 4]][j]);
            printf("\n");
        }
    }
    return 0;
}
