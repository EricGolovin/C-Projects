//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 2.6;
    double a = 1.5;
    double b = 15.5;
    double y = (pow(cos(pow(x, 3)), 2)) - (x / sqrt(pow(a, 2) + pow(b, 2)));
    printf("y = %lf\n", y);

    double P = sqrt(pow(x, 2) + b) - pow(b, 2) * pow(sin(x + a), 2) / x * y;
    printf("P = %lf\n", P);

    return 0;
}