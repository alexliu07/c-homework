#include <stdio.h>
#define swap(a, b)                                                             \
    int t = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = t;
#define elif else if
int main() {
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
    if (a[0] + a[1] <= a[2])
        printf("Not triangle\n");
    else {
        int t = a[0] * a[0] + a[1] * a[1] - a[2] * a[2];
        if (t == 0)
            printf("Right triangle\n");
        elif (t > 0) printf("Acute triangle\n");
        else printf("Obtuse triangle\n");
        if (a[0] == a[1] || a[1] == a[2])
            printf("Isosceles triangle\n");
        if (a[0] == a[1] && a[1] == a[2])
            printf("Equilateral triangle\n");
    }
    return 0;
}
