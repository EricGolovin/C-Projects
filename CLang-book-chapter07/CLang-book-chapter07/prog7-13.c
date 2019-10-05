//
//  prog7-13.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-13.h"

// Function to multiply a 3 x 5 array by a scalar

void scalarMultiplySpecific(int matrix[3][5], int scalar) {
    int row, column;

    for (row = 0; row < 3; row++) {
        for (column = 0; column < 5; column++) {
            matrix[row][column] *= scalar;
        }
    }
}

void displayMatrixSpecific(int matrix[3][5]) {
    int row, column;

    for (row = 0; row < 3; row++) {
        for (column = 0; column < 5; column++) {
            printf("%5i", matrix[row][column]);
        }
        printf("\n");
    }
}
