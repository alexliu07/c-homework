#include <stdio.h>
int main() {
    int a, r = 0;
    scanf("%d", &a);
    while (a > 0) {
        a /= 2;
        r++;
    }
    printf("%d", r);
    return 0;
}
