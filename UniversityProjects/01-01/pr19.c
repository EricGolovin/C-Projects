//
// Created by Eric Golovin on 9/23/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.3;
    double b = 0.9;
    double x = 0.53;

    double r = sqrt(pow(x, 2) + b) - pow(b, 2) * pow(sin(x + a), 3) / x;
    printf("R = %lf\n", r);

    double y = (pow(a, 2 * x) + pow(b, -x) * cos(a + b) * x) / sqrt(fabs(a - b));
    printf("Y = %lf\n", y);

    return 0;
}