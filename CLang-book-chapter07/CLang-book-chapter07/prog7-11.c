//
//  prog7-11.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-11.h"

void multiplyBy2(float array[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        array[i] *= 2;
    }
}
