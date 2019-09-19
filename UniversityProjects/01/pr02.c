//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 1.45;
    double y = -1.22;
    double z = 3.5;

    double b = 1 + pow(z, 2) / (3 + pow(z, 2) / 5);
    printf("b = %lf\n", b);

    double aUpper = 2 * cos(x - M_PI) * b;
    double aLower = 1 / 2 + pow(sin(y), 2);
    printf("aUpper = %lf\n", aUpper);
    printf("aLower = %lf\n", aLower);

    printf("a = %lf\nb = %lf", aUpper / aLower, b);

    return 0;
}

