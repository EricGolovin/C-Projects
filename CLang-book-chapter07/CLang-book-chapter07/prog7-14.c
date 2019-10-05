//
//  prog7-14.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-14.h"

// Function to multiply a 3 x 5 array by a scalar

void scalarMultiply(int nRows, int nCols, int matrix[nRows][nCols], int scalar) {
    int row, column;

    for (row = 0; row < nRows; row++) {
        for (column = 0; column < nCols; column++) {
            matrix[row][column] *= scalar;
        }
    }
}

void displayMatrix(int nRows, int nCols, int matrix[nRows][nCols]) {
    int row, column;

    for (row = 0; row < nRows; row++) {
        for (column = 0; column < nCols; column++) {
            printf("%5i", matrix[row][column]);
        }
        printf("\n");
    }
}
