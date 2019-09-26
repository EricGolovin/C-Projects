//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
	double triangularSides[3];

	printf("Please, enter 3 sides of the triangular: \n");

	for (int i = 0; i <= 2; i++) {
		printf("Enter side #%i: ", i+1);
		scanf("%lf", &triangularSides[i]);
	}

	double halfPerimeter = (triangularSides[0] + triangularSides[1] + triangularSides[2]) / 2.0;
	double squareRoot = sqrt((halfPerimeter - triangularSides[0]) * (halfPerimeter - triangularSides[1]) * (halfPerimeter - triangularSides[2]));

	printf("**************************\n");
	printf("HalfPerimeter = %lf\n", halfPerimeter);
	printf("Square Root = %lf\n", squareRoot);

	for (int i = 0; i <= 2; i++) {
		switch(i) {
			case 0:
                printf("Height_a = %.3lf\n", (2 / triangularSides[0]) * squareRoot);
                break;
		    case 1:
                printf("Height_b = %.3lf\n", (2 / triangularSides[1]) * squareRoot);
                break;
		    case 2:
                printf("Height_a = %.3lf\n", (2 / triangularSides[2]) * squareRoot);
                break;
            default:
                break;
        }
    }

    return 0;
}
