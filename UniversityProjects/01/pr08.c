//
// Created by Eric Golovin on 9/19/19.
//

#include <stdio.h>
#include <math.h>

int main(void) {
	double qModule;
	double x = 1.82;
	double y = 18.5;
	double z = 3.4;

	double f = (x - y) * (y - z / (y - x) / (1 + (pow(y - x, 2))));
	printf("f = %fl\n", f);

	double q = pow(x, y / x) - pow(sqrt(y / x), 3);

	if (q >= 0) {
		qModule = q;
	} else {
		qModule = -pow(x, y / x) + pow(sqrt(y / x), 3);
	}

	printf("q = %lf\n", qModule);

	return 0;
}