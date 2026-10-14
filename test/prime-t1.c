#include <stdio.h>
#define N 50000000
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
int nums[N];
int main() {
    freopen("prime.out", "w", stdout);
    int n = 0;
    for (int i = 1; i <= N; i++) {
        if (isPrime(i)) {
            nums[n] = i;
            n++;
        }
    }
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d,", nums[i]);
    }
    printf("}\n%d",n);
    return 0;
}
