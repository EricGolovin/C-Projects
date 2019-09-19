//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double a = -0.5;
    double b = 1.7;
    double t = 0.44;
    double moduleOperation;

    double s = b * sin(a * pow(t, 2) * cos(2 * t)) - 1;
    printf("s = %lf\n", s);

    if ((b * t + a) >= 0) {
        moduleOperation = (b * t + a);
    } else {
        moduleOperation = (-b * t - a);
    }

    double y = exp(-b * t) * sin(a * t + b) - sqrt(moduleOperation);
    printf("y = %lf\n", y);

    return 0;
}