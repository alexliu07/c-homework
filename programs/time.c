#include <stdio.h>
int main() {
    char month[20] = {0}, day[20] = {0};
    int date, year, tim[3];
    scanf("%s%d%d%s%d%d%d", month, &date, &year, day, &tim[0], &tim[1],
          &tim[2]);
    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", day, month, date, tim[0], tim[1],
           tim[2], year);
    return 0;
}
