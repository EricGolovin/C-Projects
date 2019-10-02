#include <stdio.h>

double  squereRoot(double  x, const double  epsilon) {
	double  guess = 1.0;
	double   absoluteValue(double  x);
	printf("\nguess = %f\n", guess);

	if (x < 0) {
		printf("Negative value to squereRoot\n");
		return -1.0;
	}

	while (absoluteValue(guess / x) >= epsilon) {
		guess = (x / guess + guess) / 2.0;
		printf("guess = %f\n", guess);
	}

	printf("-----------------------");

	return guess;
}

double  absoluteValue(double  x) {
	if (x < 0) {
		x = -x;
	}

	return x;
}

int main(void) {
	printf("squereRoot(2.0) = %la\n", squereRoot(2.0, .000001));
	printf("squereRoot(144.0) = %la\n", squereRoot(144.0, .0001));
	printf("squereRoot(17.5) = %la\n", squereRoot(17.5, .001));

	return 0;
}