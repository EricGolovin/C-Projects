//
//  main.c
//  PR-Lab02
//
//  Created by Eric Golovin on 07.10.2019.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>

int calculateTheSum(int numberOfRows, int numberOfColumns, int array[numberOfRows][numberOfColumns]) {
    void printArray(int arrayToPrint[], int numberOfElements);
    
    int upperRightNumberOfValues = (((numberOfRows * numberOfColumns) - numberOfRows) / 2);
    int sum = 1;
    int i = 0;
    
    int sumArray[upperRightNumberOfValues - 1];
    
    for (int row = 0; row <= numberOfRows - 1; row++) {
        for (int column = 0; column <= numberOfColumns - 1; column++) {
            
//            if (row == 0 && column > 0) {
//                printf("adding %i to sumArray[%i]\n", array[row][column], i);
//                sumArray[i] = array[row][column];
//                i++;
//            } else if (row == 1 && column > 1) {
//                printf("02adding %i to sumArray[%i]\n", array[row][column], i);
//                sumArray[i] = array[row][column];
//                i++;
//            } else if (row == 2 && column > 2) {
//                printf("03adding %i to sumArray[%i]\n", array[row][column], i);
//                sumArray[i] = array[row][column];
//                i++;
//            }
            
            if (column > row) { // < for secondary diagonal
                sumArray[i] = array[row][column];
                i++;
            }
        }
    }
    
    for (int index = 0; index <= upperRightNumberOfValues - 1; index++) {
        if (sumArray[index] % 2 == 0) {
            sum *= sumArray[index];
        }
    }
    
    return sum;
}

void printArray(int arrayToPrint[], int numberOfElements) {
    for (int index = 0; index < numberOfElements; index++) {
        printf("[%i] = %i", index, arrayToPrint[index]);
    }
}

int main(void) {
    int array[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int sum = calculateTheSum(4, 4, array);
    printf("%i\n", sum);
    return 0;
}
