#include <stdio.h>
char table[101][101];
int main() {
    int n;
    char tmp;
    scanf("%d%c", &n, &tmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%c", &table[i][j]);
        }
        scanf("%c", &tmp);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j] == '*') {
                printf("*");
                continue;
            }
            int sum = 0;
            for (int k = 0; k < 9; k++) {
                int c = i + (k / 3 - 1), r = j + (k % 3 - 1);
                if (c < 1 || r < 1 || c > n || r > n || (c == i && r == j))
                    continue;
                if (table[c][r] == '*')
                    sum++;
            }
            printf("%d", sum);
        }
        printf("\n");
    }
    return 0;
}
