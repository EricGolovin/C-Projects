//
//  prog7-ex10.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-ex10.h"

int checkForPrime(int valueToCheck) {
    for (int i = 2; i < valueToCheck; i++) {
        if ((valueToCheck % i) == 0) {
            return 0;
            break;
        }
    }
    return 1;
}
