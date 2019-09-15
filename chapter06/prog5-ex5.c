#include <stdio.h>

int main(void) {
	int number, right_digit;

	printf("Please, enter your number: ");
	scanf("%i", &number);

	do {
		right_digit = number % 10;
		if (right_digit < 0) {
			printf("%i", -right_digit);
		} else {
			printf("%i", right_digit);
		}
		number /= 10;
		if (right_digit < 0 && number == 0) {
			printf("-");
		}
	} while (number != 0);

	return 0;
}
