#include <stdio.h>
#include <string.h>
int exist[10] = {0};
int isComplete() {
    int flag = 1;
    for (int i = 1; i <= 9; i++) {
        if (!exist[i]) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int table[9][9];
int main() {
    int flag = 0;
    for (int i = 0; i < 9; i++) {
        memset(exist, 0, sizeof(exist));
        for (int j = 0; j < 9; j++) {
            scanf("%d", &table[i][j]);
            exist[table[i][j]] = 1;
        }
        if (!isComplete()) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        memset(exist, 0, sizeof(exist));
        for (int j = 0; j < 9; j++) {
            exist[table[j][i]] = 1;
        }
        if (!isComplete()) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        memset(exist, 0, sizeof(exist));
        for (int j = 0; j < 9; j++) {
            int c = (i / 3) * 3 + j / 3, r = (i % 3) * 3 + j % 3;
            exist[table[c][r]] = 1;
        }
        if (!isComplete()) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}
