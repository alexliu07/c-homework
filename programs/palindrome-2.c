#include <stdio.h>
#include <string.h>
#define N 100001
char s[N];
int dict[N];
int main() {
    int n, b, cur = 0;
    memset(dict, -1, sizeof(dict));
    scanf("%d%s", &n, s);
    b = strlen(s);
    for (int i = 0; i < b; i++) {
        if (s[i] == s[n - i - 1] && s[i] == '?') {
            if (dict[i] == -1) {
                int rev = 0;
                if (cur < 10)
                    rev = cur * 10;
                else {
                    int t = cur;
                    while (t > 0) {
                        rev = rev * 10 + t % 10;
                        t /= 10;
                    }
                }
                dict[i] = cur;
                dict[n - i - 1] = rev;
                cur++;
            }
            printf("%.2d", dict[i]);
        } else if (s[i] == '?')
            printf("%c", s[n - i - 1]);
        else
            printf("%c", s[i]);
    }
    return 0;
}
