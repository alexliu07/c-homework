#include <stdio.h>
#define elif else if
int main() {
    int m;
    scanf("%d", &m);
    if (m > 100)
        printf("Wrong score");
    elif (m >= 90 && m <= 100) printf("A");
    elif (m >= 80 && m < 90) printf("B");
    elif (m >= 70 && m < 80) printf("C");
    elif (m >= 60 && m < 70) printf("D");
    else printf("F");
    return 0;
}
