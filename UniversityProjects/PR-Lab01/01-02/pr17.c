<<<<<<< HEAD
//
// Created by Eric Golovin on 9/24/19.
//

int main(void) {
    double x = 1;
    double indexX = 0.5;
    double a = 2;
    double indexA = 1;

    for (a = 2; a <= 10; x += indexX, a += indexA) {
        printf("a2 + x = %lf", pow(a, 2) + x);
    }

    return 0;
}
=======
#include <stdio.h>
#include <math.h>

int main(void) {
	double x;
	double indexX = 0.5;
	double a;
	double indexA = 1.0;

	for (x = 1, a = 2; x <= 8.1; x += indexX) {
		if (a <= 10.1) {
			a += indexA;
		}

		if (a > x) {
			printf("%.2lf ^2 + %.2lf ==> %.2lf\n", a, x, pow(a, 2) + x);
		} else if (a = x) {
			printf("%.2lf ^2 ==> %.2lf\n", x, pow(a, 2));
		}
		else if (a < x) {
			printf("%.2lf ^2 - %.2lf ==> %.2lf\n", a, x, pow(a, 2) - x);
		}
	}

	return 0;
}
>>>>>>> 5a9624df136b5204235bafa37d2738e014d5f2db
