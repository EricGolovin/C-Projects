//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double diameter;
    double radius;
    double height;

    printf("Please, enter diameter of the Cone (R): ");
    scanf("%lf", &diameter);
    printf("Please, enter radius of the Cone (r): ");
    scanf("%lf", &radius);
    printf("Please, enter height of the Cone (h): ");
    scanf("%lf", &height);

    double coneApothem = sqrt(pow(height, 2) + (diameter - radius));
    double coneArea = (M_PI * (diameter + radius) * coneApothem) + (M_PI * pow(diameter, 2)) + (M_PI * pow(radius, 2));
    double coneVolume = (M_PI / 3) * (pow(diameter, 2) + pow(radius, 2) + (diameter * radius)) * height;

    printf("S = %.3lf\nl = %.3lf\nV = %.3lf", coneArea, coneApothem, coneVolume);

    return 0;
}