#include <stdio.h>

int main() {
	int dotX = 33, dotY = -3;

	if (dotX > 0 && dotY > 0) {
		printf("Dot in the 1st quarter");
	} else if (dotX < 0 && dotY > 0) {
		printf("Dot in the 2ne quarter");
	} else if (dotX < 0 &&  dotY < 0) {
		printf("Dot in the 3rd quarter");
	} else if (dotX > 0 && dotY < 0) {
		printf("Dot in the 4th quarter");
	}

	return 0;
}
