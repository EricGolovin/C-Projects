#include <stdio.h>

int main(void) {
	int raitingCounter[9], i, response;

	for (i = 0; i <= 9; i++) {
		raitingCounter[i] = 0;
	}

	printf("Enter your responses\n");

	for (i = 1; i <= 20; i++) {
		printf("Response #%i: ", i);
		scanf("%i", &response);

		if (response < 1 || response > 10) {
			printf("Inappropriate response: %i\n", response);
		} else {
			raitingCounter[response]++;
		}
	}

	printf("\n\nRaiting   Number Of Responses\n");
	printf("-------   -------------------\n");

	for (i = 0; i <= 9; i++) {
		printf("%4i%14i\n", (i + 1), raitingCounter[i]);
	}

	return 0;
}
