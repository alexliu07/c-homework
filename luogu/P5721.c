#include <stdio.h>
int main() {
    int n, t = 1;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("%.2d", t);
            t++;
        }
        printf("\n");
    }
    return 0;
}
