#include <stdio.h>

int main(void) {
	int value1, value2;

	printf("Please enter 2 numbers: ");
	scanf("%i %i", &value1, &value2);

	if (value1 % value2 == 0) {
		printf("%i is evenly divisible by %i", value1, value2);
	} else {
		printf("%i is not evenly divisible by %i", value1, value2);
	}

	return 0;
}

