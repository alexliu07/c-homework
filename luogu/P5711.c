#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int r = (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
    printf("%d", r);
    return 0;
}
