#include <stdio.h>

int main(void) {
	float value1, value2;

	printf("Please enter two values: ");
	scanf("%f %f", &value1, &value2);

	if (value2 == 0.0) {
		printf("Division by zero");
	} else {
		printf("%.3f", value1 / value2);
	}
	return 0;
}
