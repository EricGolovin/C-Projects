#include <stdio.h>

double discriminant;
double valuesABC[2];

void calcDiscriminant() {
	for (int i = 0; i <= 2; i++) {
		printf("Please, enter value for ");
		switch (i) {
		case 0:
			printf("a: ");
			scanf("%lf", &valuesABC[0]);
			break;
		case 1:
			printf("b: ");
			scanf("%lf", &valuesABC[1]);
			break;
		case 2:
			printf("c: ");
			scanf("%lf", &valuesABC[2]);
			break;
		default:
			break;
		}
	}

	discriminant = (valuesABC[1] * valuesABC[1]) - 4 * valuesABC[0] * valuesABC[2];
}

void calcRoots() {
	calcDiscriminant();

	if (discriminant < 0) {
		printf("Roots are imaginary\n");
	}
	else {
		printf("x1 = %lf\n", (-valuesABC[2] + discriminant) / (2 * valuesABC[0]));
		printf("x2 = %lf\n", (valuesABC[2] + discriminant) / (2 * valuesABC[0]));
	}

}

int main(void) {

	calcRoots();

    return 0;
}