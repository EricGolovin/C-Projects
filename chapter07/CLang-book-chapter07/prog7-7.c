//
//  prog7-7.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-7.h"

float absoluteValue(float x) {
    if (x < 0) {
        x = -x;
    }
    
    return x;
}
