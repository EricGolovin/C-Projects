#include <stdio.h>
#include <math.h>

int main(void) {
	double a = 1;
	double b = 2;
	double indexX = 0.1;
	double indexY = 0.2;
	double x;
	double y;

	printf("\n---------- #02 ----------\n");

	for (x = 1.0, y = 1.0; x <= 2.1; x += indexX, y += indexY) {
		printf("x = %.2lf => %.2lf * %.2lf ^2 + ln(%.2lf * %.2lf * %.2lf) = %.2lf\n", x, a, x, b, x, y, (a * pow(x, 2) + log10(b * x * y)));
	}

	return 0;
}