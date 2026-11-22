#include<stdio.h>
#define N 10001
int lists[N] = {0};

int main() {
    int m, n, q;
    scanf("%d%d%d", &m, &n, &q);
    for (int i = 1; i <= m * n; i++)scanf("%d", &lists[i]);
    for (int j = 1; j <= q; j++) {
        int query, flag = 0;
        int st = 1, ed = m * n + 1, i = (st + ed) / 2;
        scanf("%d", &query);
        while (ed - st > 1) {
            if (query == lists[i]) {
                flag = 1;
                break;
            }
            if (query < lists[i]) {
                ed = i;
            } else {
                st = i;
            }
            i = (st + ed) / 2;
        }
        if (lists[st] == query || lists[ed] == query) {
            flag = 1;
        }
        if (flag)printf("true\n");
        else printf("false\n");
    }

    return 0;
}
