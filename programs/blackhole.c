#include <stdio.h>
#define swap(a, b)                                                             \
    int t = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = t;
#define ll long long
void sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}
ll sum = 0;
void eat(int n) {
    if (n == 495)
        return;
    int a[3];
    a[0] = n % 10;
    a[1] = (n / 10) % 10;
    a[2] = n / 100;
    sort(a, 3);
    int m = (a[2] * 100 + a[1] * 10 + a[0]) - (a[0] * 100 + a[1] * 10 + a[2]);
    if (n - m > 0)
        sum += n - m;
    eat(m);
}
int main() {
    int n;
    scanf("%d", &n);
    eat(n);
    printf("%lld", sum);
    return 0;
}
