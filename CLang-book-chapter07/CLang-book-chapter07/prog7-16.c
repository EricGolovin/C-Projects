//
//  prog7-16.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-16.h"

void autop_static(void) {
    int autoVar = 1; // or auto int autoVar = 1;
    static int staticVar = 1;

    printf("automatic = %i, static = %i\n", autoVar, staticVar);

    autoVar++;
    staticVar++;
}
