#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%.2d", (i - 1) * n + j);
        }
        printf("\n");
    }
    printf("\n");
    int x = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++)
            printf("  ");
        for (int j = n - i + 1; j <= n; j++) {
            printf("%.2d", x);
            x++;
        }
        printf("\n");
    }
    return 0;
}
