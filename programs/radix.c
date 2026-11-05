#include <math.h>
#include <stdio.h>
#define max(a, b) (a) > (b) ? (a) : (b)
int radix(int n, int d) {
    int result = 0;
    int i = 0;
    int m = 0;
    while (n > 0) {
        m = max(m, n % 10);
        result += (n % 10) * pow(d, i);
        i++;
        n /= 10;
    }
    if (m > d - 1)
        return -1;
    return result;
}
int main() {
    int p, q, r, s = 0;
    scanf("%d%d%d", &p, &q, &r);
    for (int i = 2; i <= 40; i++) {
        int np = radix(p, i), nq = radix(q, i), nr = radix(r, i);
        if (np == -1 || nq == -1 || nr == -1)
            continue;
        if (np * nq == nr) {
            s = i;
            break;
        }
    }
    printf("%d", s);
    return 0;
}
