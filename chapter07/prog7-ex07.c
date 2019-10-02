#include <stdio.h>

long int x_to_the_n(void) {
    long int x;
    long int multiplier;
    int n;

    printf("Please, enter x: ");
    scanf("%li", &multiplier);
    x = 1;

    printf("Please, enter n: ");
    scanf("%i", &n);

    while (n > 0) {
        x *= multiplier;
        printf("multiplier = %li\nx = %li\n\n", multiplier, x);
        n--;
    }

    return x;
}

int main(void) {
    printf("%li", x_to_the_n());
    return 0;
}