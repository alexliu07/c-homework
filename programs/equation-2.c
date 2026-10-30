#include <stdio.h>
double square(double a1, double b1, double c1, double a2, double b2, double c2,
              double a3, double b3, double c3) {
    return a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) +
           c1 * (a2 * b3 - a3 * b2);
}
int main() {
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &d1, &a2, &b2,
          &c2, &d2, &a3, &b3, &c3, &d3);
    double delta = square(a1, b1, c1, a2, b2, c2, a3, b3, c3);
    double deltax = square(d1, b1, c1, d2, b2, c2, d3, b3, c3);
    double deltay = square(a1, d1, c1, a2, d2, c2, a3, d3, c3);
    double deltaz = square(a1, b1, d1, a2, b2, d2, a3, b3, d3);
    printf("%.2f %.2f %.2f", deltax / delta, deltay / delta, deltaz / delta);
    return 0;
}
