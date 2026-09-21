#include <math.h>
#include <stdio.h>
int main() {
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    // double dis = sqrt(pow(a - x, 2) + pow(b - y, 2));
    double dis = hypot(x - a, y - b);
    double result;
    if (y == b && x > a)
        result = 90.0;
    else if (y == b && x < a)
        result = 270.0;
    else {
        double t = fabs((x - a) * 1.0 / (y - b));
        double rad = atan(t);
        double deg = rad * 180 / acos(-1);
        if (x > a && y > b)
            result = deg;
        else if (x < a && y > b)
            result = 360 - deg;
        else if (x < a && y < b)
            result = 180 + deg;
        else if (x > a && y < b)
            result = 180 - deg;
        else if (x == a && y > b)
            result = 0.0;
        else if (x == a && y < b)
            result = 180.0;
    }
    printf("%.4f %.4f", dis, result);
    return 0;
}
