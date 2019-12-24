#include <stdio.h>

int f (int a, int *b, int c) {
	printf("a++ = %i\n", a++);
	printf("++(*b) = %i\n", ++(*b));
	printf("c++ = %i\n", c++);
	return (a++ + *b + c++);
}

int main(void) {
	int a = 3, b = 1, c = 2;
	int z = f(c, &b, a);
	printf("%i%i%i%i", a, b, c, z);
	return 0;
}
