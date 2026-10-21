#include <math.h>
#include <stdio.h>
#include <string.h>
#define ll long long
int dict[1000];
int main() {
    int len, n, flag = 0;
    ll sum = 0;
    char ori[100];
    memset(dict, -1, sizeof(dict));
    for (int i = '0'; i <= '9'; i++)
        dict[i] = i - '0';
    for (int i = 'A'; i <= 'F'; i++)
        dict[i] = i - 55;
    scanf("%d%d%s", &len, &n, ori);
    for (int i = len - 1; i >= 0; i--) {
        if (dict[(unsigned char)ori[i]] == -1 || !(dict[(unsigned char)ori[i]] >= 0 && dict[(unsigned char)ori[i]] < n)) {
            flag = 1;
            break;
        }
        sum += dict[(unsigned char)ori[i]] * pow(n, len - i - 1);
    }
    if (flag)
        printf("Error");
    else
        printf("%lld", sum);
    return 0;
}
