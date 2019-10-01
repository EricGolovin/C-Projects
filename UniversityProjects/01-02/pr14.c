#include <stdio.h>
#include <math.h>

int main(void) {
	double x = -3;
	double indexX = 0.5;
	double a = 2.4;

	printf("\n---------- #01 ----------\n");
	for (; x <= 3.1; x += indexX) {
		printf("(%.2lf^%.2lf * ln|%.2lf + 2^3|) / (%.2lf + 1) ==> %lf\n", a, x, x, x, ((pow(a, x) * log10(x + pow(2, 3))) / (x + 1)));
	}

	return 0;
}