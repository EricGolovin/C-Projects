#include <stdio.h>
#include <math.h>

int main(void) {
	int a = 2, b = 4, c = 6, d = 8;
	switch (c) {
		case 2:
			printf("%i", a);
		case 4:
			printf("%i", b);
		case 6:
			printf("%i", c);
		case 8:
			printf("%i\n", d);
			break;
	}
	return 0;
}
