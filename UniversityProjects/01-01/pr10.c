//
// Created by Eric Golovin on 9/20/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double moduleValue;
    double twoFactorial = 1;
    double fourFactorial = 1;
    int counter;
    double x, y, z;

    for (int i = 0; i <= 2; i++) {
        switch (i) {
            case 0:
                printf("Please, enter value for x: ");
                scanf("%lf", &x);
                break;
            case 1:
                printf("Please, enter value for y: ");
                scanf("%lf", &y);
                break;
            case 2:
                printf("Please, enter value for z: ");
                scanf("%lf", &z);
                break;
            default:
                break;
        }
    }

    double b = x * (atan(z) + exp(x + 3));
    printf("b = %lf\n", b);


    double value = x - 1;

    for (counter = 1; counter <= 2; counter++) {
        twoFactorial *= counter;
    }

    for (counter = 1; counter <= 4; counter++) {
        fourFactorial *= counter;
    }

    double aUpper = sqrt(fabs(value)) - sqrt(y);
    double aLower = 1 + (pow(x, 2) / twoFactorial) + (pow(y, 2) / fourFactorial);
    printf("a = %lf\n", aUpper / aLower);

    return 0;
}