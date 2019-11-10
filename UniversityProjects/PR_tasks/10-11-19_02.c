#include <stdio.h>

void sumFromSmallest(int array[], int n) {
	int lowest = 0;
	int sum = 0;

	for (int i = 0; i < n; ++i) {
		if (array[i] < array[lowest]) {
			lowest = i;
		}
	}

	for (int i = lowest + 1; i < n; ++i) {
		sum += array[i];
	}
 	
 	printf("The lowest element is array[%i] = %i, and the sum of the element after the lowest one is %i\n", lowest, array[lowest], sum);
}

int main(int argc, char const *argv[])
{
	int array[8] = {9, 2, 7, 8, 0, 55, 55, 55};

	sumFromSmallest(array, 8);



	return 0;
}