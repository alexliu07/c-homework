#include <stdio.h>
#define INF 0x7fffffff
int max(int n, int m) { return n >= m ? n : m; }
int main() {
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("3 4");
    else {
        int m = n, t = 0;
        while (n > 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
            t++;
            m = max(m, n);
        }
        printf("%d %d", t, m);
    }
    return 0;
}
