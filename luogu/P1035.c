#include <stdio.h>
int main() {
    double sum = 0;
    int k, n = 0;
    scanf("%d", &k);
    while (sum <= k) {
        n++;
        sum += (1.0 / n);
    }
    printf("%d", n);
    return 0;
}
