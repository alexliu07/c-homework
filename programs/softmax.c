#include <math.h>
#include <stdio.h>
#define N 1000
double x[N] = {0}, te[N] = {0}, y[N] = {0};
double softmax(int i, double t, int n) {
    double down = 0, up = exp(x[i] / t);
    for (int j = 1; j <= n; j++)
        down += exp(x[j] / t);
    return up / down;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &x[i]);
    for (int i = 1; i <= k; i++)
        scanf("%lf", &te[i]);
    for (int i = 1; i <= k; i++) {
        double sum = 0;
        for (int j = 1; j <= n; j++) {
            y[j] = softmax(j, te[i], n);
            sum += y[j];
            printf("%.3f ", y[j]);
        }
        double avr = sum / n;
        double var = 0;
        for (int j = 1; j <= n; j++)
            var += pow(y[j] - avr, 2);
        var /= n;
        printf("%.3f\n", var);
    }
    return 0;
}
