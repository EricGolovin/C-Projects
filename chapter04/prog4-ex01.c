#include <stdio.h>

int main(void) {
	int number, powerNumber = 1;
	
	printf("Enter your number: ");
	scanf("%i", &number);

	for (int n = 1; n <= 10; n++) {
		powerNumber = number * powerNumber;
		printf("%i in %i power is %i\n", number, n, powerNumber);
	}

	return 0;
}

