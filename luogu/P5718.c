#include <stdio.h>
#define INF 0x7fffffff
int main() {
    int n, t, m = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t < m)
            m = t;
    }
    printf("%d", m);
    return 0;
}
