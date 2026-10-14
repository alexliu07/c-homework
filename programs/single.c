#include <stdio.h>
#define N 1000001
int x;
int counts[N] = {0};
int nums[N];
int main() {
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &t);
        nums[i] = t;
        counts[t]++;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        if (counts[nums[i]] == 1) {
            printf("%d", nums[i]);
            break;
        }
    }
    return 0;
}
