#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 0.5;
	double b = 2.9;
	double x = 0.3;

	double bt = a * exp(-sqrt(a)) * cos(b * x / a);
	printf("B = %lf\n", bt);

	double value = x - 1;

	double l = (pow(a, x) + pow(b, -x) * cos(a + b) * x) / sqrt(fabs(value));
	printf("L = %lf\n", l);

	return 0;
}