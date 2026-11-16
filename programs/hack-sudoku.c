#include <stdio.h>

void print(int a[]) {
    static int cnt = 0;
    cnt++;
    printf ("NO.%d: a=[", cnt);
    for (int i = 0; i < 9; i++) {
        printf("%d", a[i]);
        if (i == 9 - 1) printf("]\n");
        else printf(", ");
    }
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++)
    for (int l = 0; l < 3; l++) {
          printf("%d", a[(j * 3 + k * 3 + (l + i) % 3) % 9]);
          if (k == 3 - 1 && l == 3 - 1) printf("\n");
          else printf(" ");
    }
}

int main() {
    int a[10] = {0};

    // 保证序列单调不减
    for (a[0] = 1; a[0] <= 9; ++a[0])
    for (a[1] = a[0]; a[1] <= 9; ++a[1])
    for (a[2] = a[1]; a[2] <= 9; ++a[2])
    for (a[3] = a[2]; a[3] <= 9; ++a[3])
    for (a[4] = a[3]; a[4] <= 9; ++a[4])
    for (a[5] = a[4]; a[5] <= 9; ++a[5])
    for (a[6] = a[5]; a[6] <= 9; ++a[6])
    for (a[7] = a[6]; a[7] <= 9; ++a[7])
    for (a[8] = a[7]; a[8] <= 9; ++a[8]) {
        int sum = 0;
        long long prod = 1;

        for (int i = 0; i < 9; ++i) {
            sum += a[i];
            prod *= a[i];
        }

        if (sum == 45 && prod == 362880LL) {
            print(a);
        }
    }

    return 0;
}