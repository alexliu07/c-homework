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
        printf("not triangle");
    elif (a[0] == a[1] && a[1] == a[2]) printf("equilateral triangle");
    else {
        int t = a[0] * a[0] + a[1] * a[1] - a[2] * a[2];
        if (t == 0)
            printf("right triangle");
        else {
            if (t > 0)
                printf("acute ");
            else
                printf("obtuse ");
            if (a[0] == a[1] || a[1] == a[2])
                printf("isosceles ");
            printf("triangle");
        }
    }
    return 0;
}
