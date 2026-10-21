#include <stdio.h>
#define N 1000
int people[N] = {0};
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int last, i = 0, sum = 0, cur = 1;
    while (sum < n) {
        if (people[i]) {
            i = (i + 1) % n;
            continue;
        }
        last = i + 1;
        if (cur == k) {
            people[i] = 1;
            cur = 1;
            sum++;
        } else
            cur++;
        i = (i + 1) % n;
    }
    printf("%d", last);
    return 0;
}
