#include <stdio.h>

int main() {
	int n, number, triangularNumber;

	printf("Enter number:");
	scanf("%i", &number);

	triangularNumber = 0;

	for (n = 0; n <= number; n++) {
		triangularNumber += n;
		printf("Triangular number %i is %i\n", number, triangularNumber);
	}

	return 0;
}
