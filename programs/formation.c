#include <stdio.h>
#define N 2002
#define elif else if
int table[N][N] = {0};
int main() {
    int n, m;
    char tmp;
    scanf("%d%d", &n, &m);
    scanf("%c", &tmp);
    for (int i = 1; i <= m; i++) {
        scanf("%c", &tmp);
        table[1][i] = tmp - '0';
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int flag1 = table[i - 1][j - 1], flag2 = table[i - 1][j],
                flag3 = table[i - 1][j + 1];
            int sum = flag1 + flag2 + flag3;
            if (sum == 3)
                table[i][j] = 0;
            elif (sum == 2) table[i][j] = 1;
            elif (sum == 0) table[i][j] = 0;
            else {
                flag1 = 0;
                if (flag1 + flag2 + flag3 == 1)
                    table[i][j] = 1;
                else
                    table[i][j] = 0;
            }
            printf("%d", table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
