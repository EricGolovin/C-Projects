//
//  prog7-ex11.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-ex11.h"

int sumOfArray(int array[], int count) {
    int sum = 0;
    for (int i = 0; i <= count; i++) {
        sum += array[i];
    }
    return sum;
}
