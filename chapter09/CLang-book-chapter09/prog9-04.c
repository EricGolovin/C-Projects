//
//  prog9-04.c
//  CLang-book-chapter09
//
//  Created by Eric Golovin on 10/26/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include "prog9-04.h"

_Bool equalStrings(const char s1[], const char s2[]) {
    int i = 0;
    _Bool areEqual;
    
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    
    if (s1[i] == '\0' && s2[i] == '\0') {
        areEqual = 1;
    } else {
        areEqual = 0;
    }
    
    return areEqual;
}
