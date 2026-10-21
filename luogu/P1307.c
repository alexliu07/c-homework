#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m = 0;
    scanf("%d", &n);
    int isN = n < 0;
    n = abs(n);
    while (n > 0) {
        m = m * 10 + n % 10;
        n /= 10;
    }
    m = isN ? -m : m;
    printf("%d", m);
    return 0;
}
