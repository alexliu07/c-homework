#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int amount[5] = {50, 20, 10, 5, 1};
    for (int i = 0; i < 5; i++) {
        int tmp = n / amount[i];
        n = n - tmp * amount[i];
        printf("%d\n", tmp);
    }
    return 0;
}
