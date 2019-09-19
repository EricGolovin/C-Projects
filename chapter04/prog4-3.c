#include <stdio.h>

int main() {
	int n, triangularValue;

	printf("TABLE OF TRIANGULAR NUMBERS\n\n");
	printf(" n    Sum from 1 to n\n");
	printf("---   ---------------\n");

	triangularValue = 0;

	for (n = 1; n <= 10; n++) {
		triangularValue += n;
		printf(" %i           %i\n", n, triangularValue);
		printf("%3i           %i\n", n, triangularValue);
	}

	return 0;
}
