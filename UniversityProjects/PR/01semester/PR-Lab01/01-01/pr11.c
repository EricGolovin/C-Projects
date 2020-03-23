//
// Created by Eric Golovin on 9/20/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 1.25;
    double y = 0.93;

    double aUpper = (1 - y) * (pow(x + y, 2) / pow(x + 4, 3));
    double aLower = exp(-(x - 2)) + (pow(x, 3) + 4);
    printf("a = %lf\n", aUpper / aLower);

    double bUpper = 1 + cos(y - 2);
    double bLower = pow(x, 4 / 2) + pow(sin(y - 2), 2);
    printf("b = %lf\n", bUpper / bLower);

    printf("p = %lf\n", (aUpper / aLower) / (bUpper / bLower));

    return 0;
}
