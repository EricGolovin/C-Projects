//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 0.61;
    double a = 16.5;
    double b = 3.4;

    double c = (b * pow(x, 2) - a) / (exp(a * x) - 1);
    printf("c = %lf\n", c);

    double S = (pow(x, 3) * pow(tan(pow((x + b), 2)), 2) + a) / sqrt(x + b) * c;
    printf("S = %lf\n", S);

    return 0;
}