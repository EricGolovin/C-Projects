#include <stdio.h>

int main(void) {
	for (int n = 1; n <= 10; n++) {
		printf("Triangular number of %i is %i\n", n, n * (n + 1) / 2);
	}
	
	return 0;
}
