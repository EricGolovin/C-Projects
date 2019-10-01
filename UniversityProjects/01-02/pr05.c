//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
	double x;
	double indexX = 1;

	for (x = -5; x <= 5.1; x += indexX) {
		if (fabs(x) <= 3.1) {
			printf("\n---------- #01 ----------\n");
			printf("y(%.2lf) = sin(%.2lf + 0.4)^2 / 4 * %.2lf^2 ==> %.2lf\n", x, x, x, (sin(pow(x + 0.4, 2)) / (4 * pow(x, 2))));
		}
		else if (fabs(x) > 3) {
			printf("\n---------- #02 ----------\n");
			printf("y(%.2lf) = %.2lf^4 + 2 * %.2lf ^2 * cos(%.2lf) ==> %.2lf\n", x, x, x, x, (pow(x, 4) + 2 * pow(x, 2) * cos(x)));
		}
	}

	return 0;
}