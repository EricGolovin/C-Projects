#include <stdio.h>
#include <math.h>

int main(void) {
	double moduleValue;
	double m = 2;
	double c = -1;
	double x = 1.2;
	double b = 0.7;

	double value = c * sin(x);
	if (value >= 0) {
		moduleValue = value;
	} else {
		moduleValue = -c * -sin(x);
	}

	double f = sqrt(m * tan(x) + moduleValue);
	printf("f = %lf\n", f);

	double e = m * cos(b * x + sin(x)) + pow(c, 3);
	printf("e = %lf", e);

	return 0;
}