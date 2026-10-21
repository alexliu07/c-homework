#include <stdio.h>
#include <string.h>
#define N 100
#define ll long long
char ins[N], outs[N] = {0};
int outn[N] = {0};
int main() {
    int n, b, flag, isN, t, k;
    ll inn;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ins);
        inn = 0;
        flag = 0;
        isN = 0;
        memset(outn, 0, sizeof(outn));
        memset(outs, '0', sizeof(outs));
        b = strlen(ins);
        for (int j = 0; j < b; j++) {
            if (ins[j] != '-' && !(ins[j] >= '0' && ins[j] <= '9')) {
                flag = 1;
                break;
            }
            if (ins[j] == '-') {
                isN = 1;
                continue;
            }
            inn = inn * 10 + (ins[j] - '0');
        }
        if (flag) {
            printf("Radix Error\n");
            continue;
        }
        k = 0;
        while (inn > 0) {
            t = inn % 3 + outn[k];
            if (t == 0 || t == 1)
                outs[k] = t + '0';
            else if (t == 2) {
                outs[k] = 'Z';
                outn[k + 1]++;
            } else {
                outs[k] = '0';
                outn[k + 1]++;
            }
            k++;
            inn /= 3;
        }
        if (outn[k] == 1)
            outs[k] = '1';
        flag = 1;
        for (int i = k; i >= 0; i--) {
            if (outs[i] == '0' && flag && i != 0)
                continue;
            if (outs[i] != '0')
                flag = 0;
            if (outs[i] == 'Z' && isN)
                outs[i] = '1';
            else if (outs[i] == '1' && isN)
                outs[i] = 'Z';
            printf("%c", outs[i]);
        }
        printf("\n");
    }
    return 0;
}
