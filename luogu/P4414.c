#include <stdio.h>
#define swap(a, b)                                                             \
    int t = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = t;
int main() {
    int a[3];
    char b[4];
    scanf("%d%d%d\n%s", &a[0], &a[1], &a[2], b);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
    printf("%d %d %d", a[b[0] - 65], a[b[1] - 65], a[b[2] - 65]);
    return 0;
}
