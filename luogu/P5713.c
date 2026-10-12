#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int local = 5 * n;
    int luogu = 11 + 3 * n;
    printf(local < luogu ? "Local" : "Luogu");
    return 0;
}
