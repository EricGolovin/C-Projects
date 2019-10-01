#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 5;
	double y = 3;
	double x = -2;
	double b = 1.2;
	double indexX = 0.5;

	printf("\n---------- #01 ----------\n");

	for (x = fabs(x); x < (a / b); x += indexX) {
		printf("x = %.2lf => sin|%.2lf * %.2lf + %.2lf| = %.2lf\n", x, a, x, b, (sin(fabs(a * x + b))));
	}

	printf("\n---------- #02 ----------\n");

	for (x = fabs(x); x <= 5; x += indexX) {
		printf("x = %.2lf => cos|%.2lf * %.2lf - %.2lf| = %.2lf\n", x, a, x, b, (cos(fabs(a * x - b))));
	}

	return 0;
}