#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 3.2;
	double b = 17.5;
	double x = -4.8;

	double z = a * exp(-sqrt(3)) * cos(b * x / a);
	printf("Z = %lf\n", z);

	double y = pow(b, 3) * pow(tan(x), 2) - a / pow(sin(x / a), 2);
	printf("Y = %lf\n", y);

	return 0;
}