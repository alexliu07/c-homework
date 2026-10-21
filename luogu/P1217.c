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
int isRev(int n) {
    int tmp = n, rev = 0;
    while (tmp > 0) {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return n == rev;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (!isRev(i))
            continue;
        if (isPrime(i))
            printf("%d\n", i);
    }
    return 0;
}
