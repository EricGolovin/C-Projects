#include <stdio.h>

int main(void) {
	float floatNumbers[9];
	float value;
	float sumOfValues;

	printf("Please enter 10 floating values: \n");

	for (int i = 0; i <= 9; i++) {
		printf("Value #%i = ", i+1);
		scanf("%f", &value);

		floatNumbers[i] = value;
		sumOfValues += floatNumbers[i];
	}



	printf("AVERAGE value of floating numbers = %f", sumOfValues / 10);

	return 0;
}
