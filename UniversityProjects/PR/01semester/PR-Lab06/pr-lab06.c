#include <stdio.h>

#define MAXELEMNT(a, n) \
	for (int i = 0, maxElement = 0; i < n - 1; i++) { \
			if (a[i] < a[i + 1]) { \
				maxElement = a[i + 1]; \
			} \
			if ((i + 1) == (n - 1)) { \
				printf("%i\n", maxElement); \
			} \
	}

#define SUMELEMNT(a, n) \
 	for (int i = 0, checkpoint = 1, sum = 0; i <= n - 1; i++) { \
			if (a[i] < 0) { \
				checkpoint = 0; \
				if (i != 0) { \
					sum -= a[i - 1]; \
				} \
			} \
			if (checkpoint) { \
				sum += a[i]; \
			} \
			if (i == (n - 1)) { \
				printf("%i\n", sum); \
			} \
	}

#define CHANGEELEMENTS(a, n, x, y) \
	for (int i = 0; i <= n - 1; i++) { \
		if (a[i] >= x && a[i] <= y) { \
			a[i] = 0; \
		} \
		printf("%i ", a[i]); \
	}


int main(void) {
	int array[5] = {1, 4, 2, 53, -33};

	MAXELEMNT(array, 5);
	SUMELEMNT(array, 5);
	CHANGEELEMENTS(array, 5, 2, 55);
	return 0;
}