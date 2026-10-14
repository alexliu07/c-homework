#include <stdio.h>
int main() {
    int m, s;
    scanf("%d:%d", &m, &s);
    int nm = m - 12 * (m > 12);
    printf("%.2d:%.2d %c.m.", nm, s, m >= 12 ? 'p' : 'a');
    return 0;
}
