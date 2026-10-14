#include <stdio.h>
#define elif else if
void display_1(int n) {
    switch (n) {
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    }
}
void display_2(int n) {
    int p = n % 10;
    int q = n / 10;
    if (q == 1) {
        switch (p) {
        case 0:
            printf("ten");
            break;
        case 1:
            printf("eleven");
            break;
        case 2:
            printf("twelve");
            break;
        case 3:
            printf("thirteen");
            break;
        case 4:
            printf("fourteen");
            break;
        case 5:
            printf("fifteen");
            break;
        case 6:
            printf("sixteen");
            break;
        case 7:
            printf("seventeen");
            break;
        case 8:
            printf("eighteen");
            break;
        case 9:
            printf("nineteen");
            break;
        }
    } else {
        switch (q) {
        case 2:
            printf("twenty");
            break;
        case 3:
            printf("thirty");
            break;
        case 4:
            printf("forty");
            break;
        case 5:
            printf("fifty");
            break;
        case 6:
            printf("sixty");
            break;
        case 7:
            printf("seventy");
            break;
        case 8:
            printf("eighty");
            break;
        case 9:
            printf("ninety");
            break;
        }
        if (p != 0) {
            printf("-");
            display_1(p);
        }
    }
}
void display_3(int n) {
    int p = n % 100;
    int q = n / 100;
    display_1(q);
    if (p == 0)
        printf(" hundred");
    elif (p / 10 == 0) {
        printf(" hundred and ");
        display_1(p);
    }
    else {
        printf(" hundred and ");
        display_2(p);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0)
        printf("zero");
    else {
        int bits = 0, t = n;
        while (t > 0) {
            bits++;
            t /= 10;
        }
        switch (bits) {
        case 1:
            display_1(n);
            break;
        case 2:
            display_2(n);
            break;
        case 3:
            display_3(n);
            break;
        }
    }
    return 0;
}
