#include <stdio.h>
#include <string.h>
#define N 2000
char a[N] = {0}, b[N] = {0};

int main() {
    int n;
    scanf("%d", &n);
    a[0] = '.';
    a[1] = '.';
    a[2] = '.';
    b[0] = '.';
    b[1] = '.';
    b[2] = '.';
    scanf("%s", a + 3);
    int s = strlen(a);
    a[s] = '.';
    a[s + 1] = '.';
    a[s + 2] = '.';
    b[s] = '.';
    b[s + 1] = '.';
    b[s + 2] = '.';
    s = strlen(a);
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j < s - 3; j++) {
            int cnt[2] = {0, 0};
            for (int k = j - 3; k <= j + 3; k++) {
                if (k == j)
                    continue;
                if (a[k] != '.')
                    cnt[a[k] - 'A']++;
            }
            if (a[j] == '.') {
                if (cnt[0] >= 2 && cnt[0] <= 4 && cnt[1] == 0)
                    b[j] = 'A';
                else if (cnt[1] >= 2 && cnt[1] <= 4 && cnt[0] == 0)
                    b[j] = 'B';
                else
                    b[j] = '.';
            } else {
                if (cnt[(a[j] - 'A' + 1) % 2] > 0 || cnt[a[j] - 'A'] >= 5 ||
                    cnt[a[j] - 'A'] <= 1)
                    b[j] = '.';
                else
                    b[j] = a[j];
            }
        }
        strncpy(a, b, s);
    }
    for (int i = 3; i < s - 3; i++) {
        printf("%c", a[i]);
    }
    return 0;
}
