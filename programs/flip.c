#include <stdio.h>
#define N 10000
// int series[N] = {0};
int main() {
    int n;
    scanf("%d", &n);
    // for (int i = 1; i <= n; i++)
    //     for (int j = i; j <= n; j += i)
    //         series[j] = !series[j];
    // for (int i = 1; i <= n; i++)
    //     if (series[i])
    //         printf("%d ", i);
    for (int i = 1; i * i <= n; i++)
        printf("%d ", i * i);
    return 0;
}
