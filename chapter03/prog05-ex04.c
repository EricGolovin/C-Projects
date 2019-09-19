#include <stdio.h>

int main(void) {
	int i1 = 365;
	int j1 = 7;

	int i2 = 12258;
	int j2 = 23;

	printf("The largest even multiple of %i and %i is %i\n", i1, j1, (i1 + j1 - i1 % j1));
	printf("The largest even multiple of %i and %i is %i", i2, j2, (i2 + j2 - i2 % j2));

	return 0;
}
