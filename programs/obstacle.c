#include <stdio.h>
#include <stdlib.h>
#define N 1000000
char outp[N] = {0};
int head = 0;
void push(char x) {
    outp[head] = x;
    head++;
}
void display() {
    for (int i = 0; i < head; i++) {
        printf("%c", outp[i]);
    }
}
int main() {
    int xa, ya, xb, yb, xc, yc;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    int vert = abs(ya - yb);
    int hori = abs(xa - xb);
    int n = 0;
    if (xa == xb) {
        int i = ya;
        if (ya > yb) {
            while (i > yb) {
                if (i - 1 == yc && xa == xc) {
                    push('R');
                    push('D');
                    push('D');
                    push('L');
                    n += 4;
                    i -= 2;
                } else {
                    push('D');
                    n++;
                    i--;
                }
            }
        } else {
            while (i < yb) {
                if (i + 1 == yc && xa == xc) {
                    push('R');
                    push('U');
                    push('U');
                    push('L');
                    n += 4;
                    i += 2;
                } else {
                    push('U');
                    n++;
                    i++;
                }
            }
        }
        printf("%d\n", n);
        display();
        return 0;
    }
    if (ya == yb) {
        if (xa > xb) {
            int i = xa;
            while (i > xb) {
                if (i - 1 == xc && ya == yc) {
                    push('D');
                    push('L');
                    push('L');
                    push('U');
                    n += 4;
                    i -= 2;
                } else {
                    push('L');
                    n++;
                    i--;
                }
            }
        } else {
            int i = xa;
            while (i < xb) {
                if (i + 1 == xc && ya == yc) {
                    push('D');
                    push('R');
                    push('R');
                    push('U');
                    n += 4;
                    i += 2;
                } else {
                    push('R');
                    n++;
                    i++;
                }
            }
        }
        printf("%d\n", n);
        display();
        return 0;
    }
    n = hori + vert;
    printf("%d\n", n);
    int mode = 0;
    if (xa > xb && ya > yb) {
        for (int i = xa; i >= xb; i--) {
            if (i == xc && ya == yc) {
                mode = 1;
                break;
            }
        }

        for (int i = ya; i >= yb; i--) {
            if (i == yc && xb == xc) {
                mode = 1;
                break;
            }
        }
        if (mode) {
            for (int i = 1; i <= vert; i++)
                printf("D");
            for (int i = 1; i <= hori; i++)
                printf("L");
        } else {
            for (int i = 1; i <= hori; i++)
                printf("L");
            for (int i = 1; i <= vert; i++)
                printf("D");
        }
    } else if (xa < xb && ya > yb) {
        for (int i = xa; i <= xb; i++) {
            if (i == xc && ya == yc) {
                mode = 1;
                break;
            }
        }
        for (int i = ya; i >= yb; i--) {
            if (i == yc && xb == xc) {
                mode = 1;
                break;
            }
        }
        if (mode) {
            for (int i = 1; i <= vert; i++)
                printf("D");
            for (int i = 1; i <= hori; i++)
                printf("R");
        } else {
            for (int i = 1; i <= hori; i++)
                printf("R");
            for (int i = 1; i <= vert; i++)
                printf("D");
        }
    } else if (xa > xb && ya < yb) {
        for (int i = xa; i >= xb; i--) {
            if (i == xc && ya == yc) {
                mode = 1;
                break;
            }
        }
        for (int i = ya; i <= yb; i++) {
            if (i == yc && xb == xc) {
                mode = 1;
                break;
            }
        }
        if (mode) {
            for (int i = 1; i <= vert; i++)
                printf("U");
            for (int i = 1; i <= hori; i++)
                printf("L");
        } else {
            for (int i = 1; i <= hori; i++)
                printf("L");
            for (int i = 1; i <= vert; i++)
                printf("U");
        }
    } else if (xa < xb && ya < yb) {
        for (int i = xa; i <= xb; i++) {
            if (i == xc && ya == yc) {
                mode = 1;
                break;
            }
        }
        for (int i = ya; i <= yb; i++) {
            if (i == yc && xb == xc) {
                mode = 1;
                break;
            }
        }
        if (mode) {
            for (int i = 1; i <= vert; i++)
                printf("U");
            for (int i = 1; i <= hori; i++)
                printf("R");
        } else {
            for (int i = 1; i <= hori; i++)
                printf("R");
            for (int i = 1; i <= vert; i++)
                printf("U");
        }
    }
    return 0;
}
