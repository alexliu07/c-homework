#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int x = n % 2 == 0, y = n > 4 && n <= 12;
    int a = x && y, b = x || y, c = (x || y) && (!(x && y)), d = !(x || y);
    printf("%d %d %d %d", a, b, c, d);
    return 0;
}
