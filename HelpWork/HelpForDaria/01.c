#include <stdio.h>
#include <math.h>

int main() {
	int circleArea = 55 * M_PI;	
	int circleDiameter = sqrt(circleArea / M_PI) * 2;
	int circleLenght = circleDiameter / 2 * 2 * M_PI;

	printf("circleArea = %i, circleDiameter = %i, circleLenght = %i\n", circleArea, circleDiameter, circleLenght);

	return 0;
}
