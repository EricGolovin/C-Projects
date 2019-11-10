#include <stdio.h>

int main() {
	int a = 2, b = 4, c = -1;

	if (a > 0 && b > 0) {
		printf("a and b > 0");
	} else if (a > 0 && c > 0) {
		printf("a and c > 0");
	} else if (b > 0 && c > 0) {
		printf("b and c > 0");
	} else {
		printf("There is no number that is > 0");
	}

	return 0;
}
