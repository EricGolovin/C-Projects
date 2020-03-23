//
// Created by Eric Golovin on 9/20/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0.43;
    double a = 0.7;
    double b = 0.05;

    double rUpper = pow(x, 2) * (x + 1);
    double rLower = b - pow(sin(x - a), 2);
    printf("R = %lf\n", (rUpper / rLower));

    double cosValue = cos(pow(a + b, 3));

    double s = sqrt(x * b / a) + fabs(cosModule);
    printf("S = %lf", s);

    return 0;
}