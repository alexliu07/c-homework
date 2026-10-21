#include <stdio.h>
#define N 10000
char s[N];
int main() {
    int n;
    char tmp;
    scanf("%d", &n);
    scanf("%c", &tmp);
    for (int i = 0; i < n; i++)
        scanf("%c", &s[i]);
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')
            printf("%c", s[n - i - 1]);
        else
            printf("%c", s[i]);
    }
    return 0;
}
