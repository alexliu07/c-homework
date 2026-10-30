#include <stdio.h>
#include <string.h>
#define N 2000
char a[N] = {0}, b[N] = {0};
int main() {
    int n, sum;
    scanf("%d", &n);
    scanf("%s", a + 3);
    a[0] = '.';
    a[1] = '.';
    a[2] = '.';
    sum = strlen(a);
    for (int i = 0; i < n; i++) {
        memset(b, '.', sizeof(b));
        for (int j = 3; j < sum; j++) {
            if (a[j] == '.') {
                int sumA = 0, sumB = 0;
                for (int k = j - 3; k <= j + 3; k++) {
                    if (k == j)
                        continue;
                    sumA += a[k] == 'A';
                    sumB += a[k] == 'B';
                }
                if (sumB == 0 && sumA >= 2 && sumA <= 4)
                    b[j] = 'A';
                else if (sumA == 0 && sumB >= 2 && sumB <= 4)
                    b[j] = 'B';
                else
                    b[j] = '.';
            } else {
                int sum[2] = {0};
                for (int k = j - 3; k <= j + 3; k++) {
                    if (k == j)
                        continue;
                    sum[0] += a[k] == 'A';
                    sum[1] += a[k] == 'B';
                }
                if (sum[(a[j] - 'A' + 1) % 2] > 0 || sum[a[j] - 'A'] >= 5 ||
                    sum[a[j] - 'A'] <= 1)
                    b[j] = '.';
                else
                    b[j] = a[j];
            }
        }
        strncpy(a, b, sum);
    }
    for (int i = 3; i < sum; i++) {
        printf("%c", a[i]);
    }
    return 0;
}
