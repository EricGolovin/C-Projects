#include <stdio.h>

int main(void) {
	int arrayValues[10] = {0, 1, 4, 9, 16};
	int i;

	for (i = 5; i < 10; i++) {
		arrayValues[i] = i * i;
	}

	for (i = 0; i < 10; i++) {
		printf("arrayValues[%i] = %i\n", i, arrayValues[i]);
	}

	return 0;
}

