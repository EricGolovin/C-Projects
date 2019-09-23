#include <stdio.h>

int main(void) {
	float number, accumulator;
	char operator;
	_Bool switcher = 1;

	while (switcher) {
		printf("Enter your operation on accumulator: ");
		scanf("%f %c", &number, &operator);

		switch (operator) {
			case 's':
			case 'S':
				accumulator = number;
				break;
			case 'e':
			case 'E':
				printf("Accumulator = %f", accumulator);
				switcher = 0;
				break;
			case '+':
				accumulator += number;
				break;
			case '-':
				accumulator -= number;
				break;
			case '*':
				accumulator *= number;
				break;
			case '/':
				accumulator /= number;
				break;
			default:
				printf("Unknown operator");
				break;
		}
	}

	return 0;
}	
