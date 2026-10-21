#include <stdio.h>
int main() {
    // 01  02  03  04  05  06  07
    // Mo  Tu  We  Th  Fr  Sa  Su
    //      1   2   3   4   5   6
    //  7   8   9  10  11  12  13
    // 14  15  16  17  18  19  20
    // 21  22  23  24  25  26  27
    // 28  29  30  31
    int m, n;
    scanf("%d%d", &m, &n);
    n = (n + 6) % 7 == 0 ? 7 : (n + 6) % 7;
    int cur = 1, rows = (m - (8 - n)) % 7 == 0 ? (m - (8 - n)) / 7 + 1
                                               : (m - (8 - n)) / 7 + 2;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= 7; j++) {
            if (i == 1 && j < n)
                printf("  ");
            else {
                if (cur < 10)
                    printf(" %d", cur);
                else
                    printf("%d", cur);
                cur++;
            }
            if (cur > m)
                break;
            if (j < 7)
                printf("  ");
        }
        if (i < rows)
            printf("\n");
    }
    return 0;
}
