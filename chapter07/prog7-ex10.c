#include <stdio.h>

int checkForPrime(int valueToCheck) {
    for (int i = 2; i < valueToCheck; i++) {
        if ((valueToCheck % i) == 0) {
            return 0;
            break;
        }
    }
    return 1;
}

int main(void) {
    int value;
    printf("Please, enter value to check for Prime: ");
    scanf("%i", &value);

    printf("%i is prime(1) or not prime(0) --> %i", value, checkForPrime(value));
    return 0;
}