#include <stdio.h>

void transposeMatrix(int workingArray[3][4], int numberOfRows, int numberOfColumns) {
    int newArray[numberOfColumns][numberOfRows];

    for (int row = 0; row <= numberOfRows; row++) {
        for (int column = 0; column <= numberOfColumns; column++) {
            newArray[numberOfColumns][numberOfRows] = workingArray[numberOfRows][numberOfColumns];
        }
    }
}

void displayMatrix(int matrix[3][4]) {
    int row, column;

    for (row = 0; row <= 3; row++) {
        for (column = 0; column <= 5; column++) {
            printf("%5i", matrix[row][column]);
        }
    }
}

int main(void) {
    int array[3][4] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4} };
    transposeMatrix(array, 3, 4);
    displayMatrix(array);
    return 0;
}