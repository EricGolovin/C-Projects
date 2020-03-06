#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateError(double num, double w) {
	int digitCount = 0;
	double numCopy = num;
	
	while (numCopy - (double)((int)numCopy) != 0) {
		numCopy *= 10;
	}

	int cpOfnumCopy = numCopy;

	while (cpOfnumCopy != 0) {
              digitCount += 1;
              cpOfnumCopy /= 10;
        }
	
	return w / ((int)num * pow(10, digitCount - 1)) * (int)num; 
}

int main(int argc, char *argv[]) {
	if (argc == 3) {
		printf("Error = %f\n", calculateError(atof(argv[1]), atof(argv[2])));
	} else if (argc == 5) {
		printf("Error01 = %f\n", calculateError(atof(argv[1]), atof(argv[2])));
		printf("Error02 = %f\n", calculateError(atof(argv[3]), atof(argv[4])));
	}	

	return 0;
}
