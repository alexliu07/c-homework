#include <math.h>
#include <stdio.h>
int main() {
    long long p, q;
    scanf("%lld%lld", &p, &q);
    double result, middle = sqrt(pow(q * 1.0 / 2, 2) + pow(p * 1.0 / 3, 3));
    if (-(q * 1.0 / 2) - middle < 0 && middle - (q * 1.0 / 2) > 0) {
        result = pow(middle - (q * 1.0 / 2), 1.0 / 3.0) -
                 pow(middle + (q * 1.0 / 2), 1.0 / 3.0);
    } else if (-(q * 1.0 / 2) - middle > 0 && middle - (q * 1.0 / 2) < 0) {
        result = -pow((q * 1.0 / 2) - middle, 1.0 / 3.0) +
                 pow(-(q * 1.0 / 2) - middle, 1.0 / 3.0);
    } else if (-(q * 1.0 / 2) - middle < 0 && middle - (q * 1.0 / 2) < 0) {
        result = -pow((q * 1.0 / 2) - middle, 1.0 / 3.0) -
                 pow((q * 1.0 / 2) + middle, 1.0 / 3.0);
    } else {
        result = pow(-(q * 1.0 / 2) + middle, 1.0 / 3.0) +
                 pow(-(q * 1.0 / 2) - middle, 1.0 / 3.0);
    }
    printf("%.3f", result);
    return 0;
}
