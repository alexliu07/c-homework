#include <math.h>
#include <stdio.h>
int main() {
    double result1 =
        log(pow(5280, 3) * pow(236674.0 + 30303.0 * sqrt(61), 3) + 744) /
        sqrt(427);
    double result2 =
        4 * (6 * atan(1.0 / 8) + 2 * atan(1.0 / 57) + atan(1.0 / 239));
    printf("%.15f\n%.15f", result1, result2);
    return 0;
}
