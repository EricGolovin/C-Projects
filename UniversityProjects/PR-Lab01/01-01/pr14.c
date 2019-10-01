#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 1.1;
	double b = 0.004;
	double x = 0.2;

	double y = pow(sin(pow((pow(x, 2) + a), 2)), 3) - pow(sqrt(x / b), 3);
	printf("y = %lf\n", y);

	double z = pow(x, 2) / a + pow(cos(pow(x + b, 3)), 2);
	printf("z = %lf\n", z);

	return 0;
}