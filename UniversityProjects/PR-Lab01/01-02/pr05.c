#include <stdio.h>
#include <math.h>

int main(void) {
	double x;
	double indexX = 1;

	printf("\n---------- #01 ----------\n");
	for (x = -5; x <= 3.1; x += indexX) {
		printf("sin(%.2lf + 0.4)^2 / 4 * %.2lf^2 ==> %.2lf\n", x, x, (sin(pow(x + 0.4, 2)) / (4 * pow(x, 2))));
	}

	printf("\n---------- #02 ----------\n");
	for (x = 5; x > 3; x -= indexX) {
		printf("%.2lf^4 + 2 * $.2lf^2 * cos(%.2lf) ==> %.2lf\n", x, x, x, (pow(x, 4) + 2 * pow(x, 2) * cos(x)));
	}

	return 0;
}