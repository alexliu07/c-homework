#include <stdio.h>
int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    int yt = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    int result;
    if (yt && m == 2)
        result = 29;
    else if (m == 2)
        result = 28;
    else if (m <= 7)
        result = m % 2 == 0 ? 30 : 31;
    else
        result = m % 2 == 0 ? 31 : 30;
    printf("%d",result);
    return 0;
}
