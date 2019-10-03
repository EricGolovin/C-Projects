#include <stdio.h>

int sumOfArray(int array[], int count) {
    int sum = 0;
    for (int i = 0; i <= count; i++) {
        sum += array[i];
    }
    return sum;
}

int main(void) {
    int userArray[9];

    for (int i = 0; i <= 9; i++) {
        printf("Value for userArray[%i]: ", i);
        scanf("%i", &userArray[i]);
    }

    printf("Sum of all elements in userArray is %i", sumOfArray(userArray, 9));
}