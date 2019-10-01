//
// Created by Eric Golovin on 9/23/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.5;
    double b = 3.1;
    double x = 1.4;

    double l = sqrt(fabs(a * pow(x, 2) * sin(2 * x) + exp(-2 * x) * (x + b)));
    printf("L = %lf\n", l);

    double w = 1 / pow(cos(pow(x, 3)), 2) - x / pow(sqrt(pow(a, 2) + pow(b, 2)), 3);
    printf("W = %lf\n", w);

    return 0;
}
