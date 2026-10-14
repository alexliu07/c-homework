#include <math.h>
#include <stdio.h>
int main() {
    double x;
    int n;
    double sum = 0;
    scanf("%lf%d", &x, &n);
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0)
            sum += pow(x, 2 * i + 1) / (2 * i + 1);
        else
            sum -= pow(x, 2 * i + 1) / (2 * i + 1);
    }
    sum *= 4;
    printf("%.10f", sum);
    return 0;
}
