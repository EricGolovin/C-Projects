#include <stdio.h>

float squereRoot(float x) {
	const float epsilon = .000001;
	float guess = 1.0;
	float  absoluteValue(float x);
	printf("\nguess = %f\n", guess);

	if (x < 0) {
		printf("Negative value to squereRoot\n");
		return -1.0;
	}

	while (absoluteValue(guess * guess - x) >= epsilon) {
		guess = (x / guess + guess) / 2.0;
		printf("guess = %f\n", guess);
	}

	printf("-----------------------");

	return guess;
}

float absoluteValue(float x) {
	if (x < 0) {
		x = -x;
	}

	return x;
}

int main(void) {
	printf("squereRoot(2.0) = %f\n", squereRoot(2.0));
	printf("squereRoot(144.0) = %f\n", squereRoot(144.0));
	printf("squereRoot(17.5) = %f\n", squereRoot(17.5));

	return 0;
}