#include <stdio.h>
#define N 50000001
#define elif else if
int notPrime[N] = {0};
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    if (n == 1)
        printf("0");
    elif (n == 2) printf("1");
    else {
        notPrime[1] = 1;
        for (int i = 4; i <= n; i += 2)
            notPrime[i] = 1;
        for (int i = 3; i * i <= n; i += 2)
            if (!notPrime[i])
                for (int j = i * i; j <= n; j += i)
                    notPrime[j] = 1;
        for (int i = 2; i <= n; i++)
            sum += !notPrime[i];
        printf("%d", sum);
    }
    return 0;
}
