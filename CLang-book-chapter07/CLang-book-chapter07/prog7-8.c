//
//  prog7-8.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-8.h"
#include "prog7-7.h"

double  squereRoot(double  x, const double  epsilon) {
    double  guess = 1.0;
    double   absoluteValue(double  x);
    printf("\nguess = %f\n", guess);

    if (x < 0) {
        printf("Negative value to squereRoot\n");
        return -1.0;
    }

    while (absoluteValue(guess / x) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
        printf("guess = %f\n", guess);
    }

    printf("-----------------------");

    return guess;
}
