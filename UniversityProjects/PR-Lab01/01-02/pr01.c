//
// Created by Eric Golovin on 9/23/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0.75;
    double b = 1.19;
    double c = -2.5;
    double indexX = 0.1;
    double x;

    printf("\n---------- #01 ----------\n");
    for (x = 0; x < 0.5; x += indexX) {
        printf("x = %.2lf => %.2lf * %.2lf + %.2lf * cos(%.2lf) = %.2lf\n", x, a, x, b, x, (a * x + b * cos(x)));
    }

    printf("\n---------- #02 ----------\n");

    for (x = 0.5; x < 1; x += indexX) {
        printf("x = %.2lf => %.2lf * %.2lf ^2 + %.2lf * sin(2 * %.2lf) = %.2lf\n", x, b, x, c, x, (b * pow(x, 2) + c * sin(2 * x)));
    }

    return 0;
}

