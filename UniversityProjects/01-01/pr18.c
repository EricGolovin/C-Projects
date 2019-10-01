#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 10.2;
	double b = 9.3;
	double x = 2.4;
	double c = 0.5;

	double k = log10(a + pow(x, 3)) + pow(sin(x / b), 2);
	printf("K = %lf\n", k);

	double value = x - b;

	double m = (exp(-c * x) * x + pow(sqrt(x + a), 3)) / (x - sqrt(fabs(value)));
	printf("M = %lf\n", m);

	return 0;
}