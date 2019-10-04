//
//  prog7-17.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-17.h"

// Recursive function to calculate the factorial of a positive integer

unsigned long int factorial(unsigned int n) {
    unsigned long int result;

    if (n == 0) {
        result = 1;
    } else {
        result = n * factorial(n - 1);
    }

    return result;
}
