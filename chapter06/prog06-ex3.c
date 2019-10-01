#include <stdio.h>

int main(void) {
	int raitingCounter[999], i, response;
	int raitingNumber = 0;

	for (i = 0; i <= 9; i++) {
		raitingCounter[i] = 0;
	}

	printf("Enter your responses\n");

	while(1) {
		printf("Response #%i: ", raitingNumber + 1);
		scanf("%i", &response);

		if (response < 1 || response > 10) {
			printf("Inappropriate response: %i\n", response);
		} else {
			raitingCounter[response]++;
			raitingNumber++;
		}

		if (response == 999) {
			break;
		}
	}

	printf("\n\nRaiting   Number Of Responses\n");
	printf("-------   -------------------\n");

	for (i = 0; i <= raitingNumber; i++) {
		printf("%4i%14i\n", (i + 1), raitingCounter[i]);
	}

	return 0;
}
