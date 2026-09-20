#include <stdio.h>
int main() {
    char name[100] = {0}, uni;
    int pre;
    double frac, factor;
    scanf("%s%d%lf%lf %c", name, &pre, &frac, &factor, &uni);
    double sciEexp = pre + frac, conv = (pre + frac) * factor;
    int new_unit = uni - 32;
    printf("%.2s: %d (%.5f) | %.5E %.5f %c", name, pre, frac,
           sciEexp, conv, new_unit);
    return 0;
}
