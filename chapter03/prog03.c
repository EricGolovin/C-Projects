#include <stdio.h>

int main(void) {
	int a = 25;
	int b = 5;
	int c = 10;
	int d = 7;
	
	printf("a = %i, b = %i, c = %i, and d = %i\n", a, b, c, d);
	printf("a %% b = %i\n", a % c);
	printf("a %% d = %i\n", a % d);
	printf("a %% d = %i\n", a % d);
	printf("a / d * d + a && d = %i\n", a / d * d + a % d);

	return 0;
}

