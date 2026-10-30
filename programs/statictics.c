#include <stdio.h>
#include <stdlib.h>
#define N 1005
#define max(a, b) (a) > (b) ? (a) : (b)
char s[N];
int statistic[N] = {0};
int main() {
    int n, m = 0, last[2] = {0};
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; i++) {
        statistic[abs(s[i])]++;
        m = max(m, statistic[abs(s[i])]);
        last[s[i] >= 'A' && s[i] <= 'Z'] =
            max(last[s[i] >= 'A' && s[i] <= 'Z'], s[i]);
    }
    int final = last[0] - 'a' > last[1] - 'A' ? last[0] : last[1];
    for (int i = m; i > 0; i--) {
        for (int j = 'a'; j <= 'z'; j++) {
            int flag = (statistic[j] == 0) + (statistic[j - 32] == 0);
            if (flag == 2)
                continue;
            else if (flag == 1) {
                if (statistic[j] >= i)
                    printf("=");
                else if (statistic[j - 32] >= i)
                    printf("=");
                else
                    printf(" ");
            } else {
                if (statistic[j] >= i)
                    printf("=");
                else
                    printf(" ");
                if (statistic[j - 32] >= i)
                    printf("=");
                else
                    printf(" ");
            }
            if (j != final && j - 32 != final)
                printf(" ");
        }
        printf("\n");
    }
    for (int j = 'a'; j <= 'z'; j++) {
        if (statistic[j] == 0 && statistic[j - 32] == 0)
            continue;
        if (statistic[j] > 0)
            printf("-");
        if (statistic[j - 32] > 0)
            printf("-");
        if (j != final && j - 32 != final)
            printf("-");
    }
    printf("\n");
    for (int j = 'a'; j <= 'z'; j++) {
        if (statistic[j] == 0 && statistic[j - 32] == 0)
            continue;
        if (statistic[j] > 0)
            printf("%c", j);
        if (statistic[j - 32] > 0)
            printf("%c", j - 32);
        if (j != final && j - 32 != final)
            printf(" ");
    }
    return 0;
}
