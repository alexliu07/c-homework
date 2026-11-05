#include <stdio.h>
int isPrime(int n) {
    if (n == 1)
        return 0;
    int result = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result = 0;
            break;
        }
    }
    return result;
}
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int tmp = i;
        int rev = 0;
        while (tmp > 0) {
            rev *= 10;
            rev += tmp % 10;
            tmp /= 10;
        }
        if (isPrime(i) && isPrime(rev))
            sum++;
    }
    printf("%d", sum);
    return 0;
}
