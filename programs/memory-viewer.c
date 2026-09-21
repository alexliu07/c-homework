#include <stdio.h>
int main() {
    long long data[2], tmp;
    int j;
    char output[2][10] = {{'0', '0', '0', '0', '0', '0', '0', '0'},
                          {'0', '0', '0', '0', '0', '0', '0', '0'}};
    scanf("%lld%lld", &data[0], &data[1]);
    for (int i = 0; i < 2; i++) {
        j = 0;
        while (data[i] > 0) {
            tmp = data[i] % 16;
            if (tmp >= 10)
                output[i][7 - j] = tmp + 87;
            else
                output[i][7 - j] = tmp + 48;
            data[i] = data[i] / 16;
            j++;
        }
    }
    // addr:  d a t a
    printf("0x%.8s:  %c%c %c%c %c%c %c%c", output[0], output[1][0],
           output[1][1], output[1][2], output[1][3], output[1][4], output[1][5],
           output[1][6], output[1][7]);
    return 0;
}
