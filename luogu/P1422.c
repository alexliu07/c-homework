#include <stdio.h>
#define elif else if
int main() {
    int n;
    scanf("%d", &n);
    double p;
    if (n <= 150)
        p = n * 0.4463;
    elif (n <= 400) p = 66.945 + (n - 150) * 0.4663;
    else p = 183.52 + (n - 400) * 0.5663;
    printf("%.1f", p);
    return 0;
}
