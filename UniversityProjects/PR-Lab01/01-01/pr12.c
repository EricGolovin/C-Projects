//
// Created by Eric Golovin on 9/20/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0.25;
    double y = 1.31;
    double a = 3.5;
    double b = 0.9;

    double value = pow(sin(a * pow(x, 3) + b * pow(y, 2) - a * b), 3) / pow(sqrt((pow((a * pow(x, 3) + b * pow(y, 2) - a), 2) + M_PI)), 3);

    double p = fabs(value) + tan(a * pow(x, 3) + b * pow(y, 2) - a * b);
    printf("P = %lf", p);

    return 0;
}