#include <stdio.h>
int lost[16] = {0}, lostn = 0;
int checkExist(int x) {
    for (int i = 0; i < lostn; i++) {
        if (lost[i] == x)
            return 0;
    }
    return 1;
}
int bin2dec(int a, int b, int c, int d) { return 8 * a + 4 * b + 2 * c + d; }
int main() {
    char square[16] = {0};

    scanf("%s", square);
    for (int i = 0; i < 16; i++) {
        if (square[i] == '0') {
            lost[lostn] = i;
            lostn++;
        }
    }
    if (lostn == 0)
        printf("-1");
    else {
        int result = 0, lines = 0;
        for (int i = 0; i < lostn; i++) {
            int cur[4] = {0}, tmp = lost[i], j = 3;
            while (tmp > 0) {
                cur[j] = tmp % 2;
                tmp /= 2;
                j--;
            }
            int add = checkExist(bin2dec(!cur[0], cur[1], cur[2], cur[3])) +
                      checkExist(bin2dec(cur[0], !cur[1], cur[2], cur[3])) +
                      checkExist(bin2dec(cur[0], cur[1], !cur[2], cur[3])) +
                      checkExist(bin2dec(cur[0], cur[1], cur[2], !cur[3]));
            if (add == 4) {
                result = lost[i];
                break;
            }
            if (add > lines) {
                result = lost[i];
                lines = add;
            }
        }
        printf("%d", result);
    }
    return 0;
}