#include <stdio.h>
#define N 1000001
int a[N];
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pivot = a[k - 1], l = 0, r = n - 1, cur = 0, pos;
    while (l < r) {
        if (cur == 0) {
            if (a[l] >= pivot) {
                cur = 1;
                continue;
            }
            l++;
        } else {
            if (a[r] < pivot) {
                cur = 0;
                swap(&a[l], &a[r]);
                continue;
            }
            r--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == pivot) {
            pos = i;
            break;
        }
    }
    if (a[l] >= pivot)
        swap(&a[pos], &a[l]);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
