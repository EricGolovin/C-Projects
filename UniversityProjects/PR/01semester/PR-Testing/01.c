#include <stdio.h>

int main(void) {
	for (int i = 0; i < 10; i++) {
		if (i % 3 == 2) {	
			break;
		}
		printf("%i", i);	
	}
	return 0;
}
