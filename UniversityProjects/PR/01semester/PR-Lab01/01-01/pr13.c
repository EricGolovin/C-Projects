#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 0.7;
	double b = 0.05;
	double x = 0.5;

	double r = pow(x, 3) * (x + 1) / pow(b, 2) - pow(sin(x * (x + a)), 2);
	printf("R = %lf\n", r);

	double s = sqrt(x * b / a) + pow(cos(pow(x + b, 3)), 2);
	printf("%S = lf\n", s);

	return 0;
}