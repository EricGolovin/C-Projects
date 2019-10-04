//
//  prog7-10.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-10.h"

int minimum(int values[], int numberOfElements) {
    int minValue, i;

    minValue = values[0];

    for (i = 1; i < numberOfElements; i++) {
        if (values[i] < minValue) {
            minValue = values[i];
        }
    }
    return minValue;
}

