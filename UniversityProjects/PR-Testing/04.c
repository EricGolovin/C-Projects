#include <stdio.h>

struct Alphabet {
	int i;
	char c;
} sA[5] = {1, 'a', 2, 'b', 3, 'c', 4, 'd', 5, 'e'}, *psA = &sA[0];

int main(void) {
	for (int k = 0; k < 4; k++) {
		printf("%c", psA->c);
		psA++;
	}
	return 0;
}
