#include <math.h>
#include <stdio.h>
int main() {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    int a = floor((14 - month) * 1.0 / 12);
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int result = day + floor((153 * m + 2) * 1.0 / 5) + 365 * y +
                 floor(y * 1.0 / 4) - floor(y * 1.0 / 100) +
                 floor(y * 1.0 / 400) - 32045;
    printf("%d", result);
    return 0;
}
