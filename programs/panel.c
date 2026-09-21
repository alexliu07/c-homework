#include <stdio.h>
int main() {
    long long w;
    char datas[3][100] = {{0}, {0}, {0}};
    char titles[3][9] = {"ID      ", "Username", "Email   "};
    scanf("%lld", &w);
    scanf("\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 51; j++) {
            scanf("%c", &datas[i][j]);
            if (datas[i][j] == ',' || datas[i][j] == '\n') {
                datas[i][j] = 0;
                break;
            }
        }
    /**
    | ID       | 114455  |
    | Username | abcdefg |
    | Email    | a@b.c   |
     */
    for (int i = 0; i < 3; i++) {
        printf("| %s | ", titles[i]);
        for (int j = 0; j < w; j++) {
            printf("%c", datas[i][j] == 0 ? ' ' : datas[i][j]);
        }
        printf(" |\n");
    }
}
