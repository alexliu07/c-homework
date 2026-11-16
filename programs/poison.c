#include <stdio.h>
#define M 2001
char names[M][20] = {0};
int react[M][M] = {0}, pot1[25000000] = {0}, pot1n = 0, pot2[25000000] = {0},
    pot2n = 0;
void intncpy(int dest[], int ori[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = ori[i];
    }
}
int main() {
    int m, n, q;
    scanf("%d%d%d", &m, &n, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%s", names[i]);
    }
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        scanf("%d + %d = %d", &x, &y, &z);
        react[x][y] = z;
    }
    for (int l = 1; l <= q; l++) {
        char op[10] = {0};
        scanf("%s", op);
        if (op[0] == 'A') {
            int x;
            scanf("%d", &x);
            pot1[pot1n] = x;
            pot1n++;
        } else {
            for (int i = 0; i < pot1n; i++) {
                if (i == pot1n - 1) {
                    pot2[pot2n] = pot1[i];
                    pot2n++;
                    break;
                }
                int tmp = react[pot1[i]][pot1[i + 1]] > 0
                              ? react[pot1[i]][pot1[i + 1]]
                              : react[pot1[i + 1]][pot1[i]];
                if (tmp > 0) {
                    pot2[pot2n] = tmp;
                    pot2n++;
                    i++;
                } else {
                    pot2[pot2n] = pot1[i];
                    pot2n++;
                }
            }
            intncpy(pot1, pot2, pot2n);
            pot1n = pot2n;
            pot2n = 0;
        }
    }
    if (pot1n == 0)
        printf("EMPTY");
    for (int i = 0; i < pot1n; i++) {
        printf("%s\n", names[pot1[i]]);
    }
    return 0;
}