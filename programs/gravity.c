#include <stdio.h>
int main() {
    double m, r;
    scanf("%lf%lf", &m, &r);
    double result = (6.674 * 0.00000000001 * 77.15 * m) / (r * r);
    printf("%.3e", result);
    return 0;
}