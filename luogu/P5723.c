#include <stdio.h>
int isPrime(int n) {
    if (n == 1)
        return 0;
    int flag = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main() {
    int cur = 2, L, sum = 0, n = 0;
    scanf("%d", &L);
    while (sum <= L) {
        if (isPrime(cur)) {
            if (sum + cur <= L) {
                printf("%d\n", cur);
                n++;
            }
            sum += cur;
        }
        cur++;
    }
    printf("%d", n);
    return 0;
}
