#include <math.h>
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    double d5 = sqrt(5);
    double r = (pow((1.0 + d5) / 2, n) - pow((1.0 - d5) / 2, n)) / d5;
    printf("%.2f", r);
    return 0;
}
