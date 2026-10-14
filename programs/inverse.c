#include <stdio.h>
#define N 10000001
char s[N];
int main() {
    int n, k;
    scanf("%d", &n);
    char t;
    scanf("%c", &t);
    for (int i = 0; i < n; i++)
        scanf("%c", &s[i]);
    scanf("%d", &k);
    for (int i = k - 1; i >= 0; i--)
        printf("%c", s[i]);
    for (int i = n - 1; i >= k; i--)
        printf("%c", s[i]);
    return 0;
}
