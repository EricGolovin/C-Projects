//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    int counter;
    double x = 1.2;
    double y = -0.8;
    double z = pow(sin(x), 3) + pow(cos(y), 2);

    double twoValue = 1;
    double threeValue = 1;
    double fourValue = 1;

    for (counter = 1; twoValue <= 2; counter++) {
        twoValue *= counter;
    }

    for (counter = 1; threeValue <= 3; counter++) {
        threeValue *= counter;
    }

    for (counter = 1; fourValue <= 4; counter++) {
        fourValue *= counter;
    }

    double s = 1 + x + (pow(x, 2) / twoValue) + (pow(x, 3) / threeValue)+ (pow(x, 4) / fourValue);

    printf("s = %lf", s);

    return 0;
}