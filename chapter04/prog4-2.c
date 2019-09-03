#include <stdio.h>

int main() {
	int n, triangularNumber;
	
	triangularNumber = 0;

	for (n = 1; n <= 200; n = n + 10) {
		triangularNumber += n;
	}
	
	printf("The triangular number of 200 is %i", triangularNumber);

	return 0;
}
