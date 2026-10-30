#include <stdio.h>
#define N 1000
double x[N] = {0}, y[N] = {0}, theta[2] = {1, 1};
double h(double x) { return theta[0] + theta[1] * x; }
int main() {
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%lf%lf", &x[i], &y[i]);
    for (int j = 1; j <= 2000; j++) {
        double A = 0, B = 0;
        for (int i = 1; i <= m; i++) {
            double tmp = h(x[i]) - y[i];
            A += tmp;
            B += tmp * x[i];
        }
        A /= m;
        B /= m;
        theta[0] -= 0.01 * A;
        theta[1] -= 0.01 * B;
    }
    printf("y = %.3f + %.3fx", theta[0], theta[1]);
    return 0;
}
