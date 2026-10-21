#include <stdio.h>
#define INF 0x7fffffff
#define max(a, b) ((a) > (b) ? (a) : (b))
int main() {
    int T, n, tmp, ma;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        ma = -INF;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            ma = max(ma, tmp);
        }
        printf(ma == tmp ? "Yes\n" : "No\n");
    }
    return 0;
}
