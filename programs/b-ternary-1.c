#include <math.h>
#include <stdio.h>
#include <string.h>
#define N 100
char tmp[N];
int main() {
    int n, b, sum, cur, flag;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        b = strlen(tmp);
        sum = 0;
        flag = 0;
        for (int j = 0; j < b; j++) {
            if (tmp[j] == 'Z')
                cur = -1;
            else if (tmp[j] != '0' && tmp[j] != '1') {
                flag = 1;
                break;
            } else
                cur = tmp[j] - '0';
            sum += cur * pow(3, b - j - 1);
        }
        if (flag) {
            printf("Radix Error\n");
            continue;
        }
        printf("%d\n", sum);
    }
    return 0;
}
