//
//  prog7-ex12.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-ex12.h"
#include "prog7-13.h"

void transposeMatrix(int workingArray[3][5], int numberOfRows, int numberOfColumns) {
    
    int newArray[numberOfColumns][numberOfRows];

    for (int row = 0; row <= numberOfRows; row++) {
        for (int column = 0; column <= numberOfColumns; column++) {
            newArray[numberOfColumns][numberOfRows] = workingArray[numberOfRows][numberOfColumns];
        }
    }
}
