#include <stdio.h>
#include <math.h>

int main(void) {
	double x = 0.25;
	double y = 0.79;
	double z = 0.81;

	double q = pow(cos(atan(1 / z)), 2);
	printf("Q = %lf\n", q);

	double value = x - 2 * pow(x, 3) / (1 + pow(x, 2) * pow(y, 3));

	double p = (1 + pow(sin(x + 1), 2)) / (2 + fabs(value)) + pow(x, 4);
	printf("P = %lf\n", p);

	return 0;
}