#include <stdio.h>
int main() {
    int m, t, s;
    scanf("%d%d%d", &m, &t, &s);
    if (t == 0)
        printf("0");
    else {
        int r = s / t >= m ? 0 : (s % t == 0 ? m - s / t : m - s / t - 1);
        printf("%d", r);
    }
    return 0;
}
