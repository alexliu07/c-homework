#include <stdio.h>
int main() {
    double p, l, r = 8.314, t;
    scanf("%lf%lf%lf", &p, &l, &t);
    double n = (p * l * l * l) / (r * t);
    printf("%.4e", n);
    return 0;
}
