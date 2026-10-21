#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int main() {
    int n, last = 0, tmp, sum = 1, res = 0,flag=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (last == 0) {
            last = tmp;
            continue;
        }
        if (tmp - last == 1){
            flag = 1;
            sum++;
        }
        else {
            res = max(res, sum);
            sum = 1;
            flag = 0;
        }
        last = tmp;
    }
    if(flag)res = max(res, sum);
    printf("%d", res);
    return 0;
}
