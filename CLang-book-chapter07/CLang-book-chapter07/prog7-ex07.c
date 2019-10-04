//
//  prog7-ex07.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-ex07.h"

long int x_to_the_n(void) {
    long int x;
    long int multiplier;
    int n;

    printf("Please, enter x: ");
    scanf("%li", &multiplier);
    x = 1;

    printf("Please, enter n: ");
    scanf("%i", &n);

    while (n > 0) {
        x *= multiplier;
        printf("multiplier = %li\nx = %li\n\n", multiplier, x);
        n--;
    }

    return x;
}
