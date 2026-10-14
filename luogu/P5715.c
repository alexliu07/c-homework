#include <stdio.h>
#define swap(a, b)                                                             \
    int t = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = t;
int main() {
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < 3; i++)
        printf("%d ", a[i]);
    return 0;
}
