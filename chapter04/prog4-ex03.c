#include <stdio.h>

int main(void) {
	int n, number, factorialNumber;

	printf("Enter your number: ");
	scanf("%i", &number);

	factorialNumber = 1;

	for (n = 1; n <= number; n++) {
		factorialNumber = factorialNumber * n;
	}

	printf("%i! = %i", n, factorialNumber);

	return 0;
}

