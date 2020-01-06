//
//  prog9-01.c
//  CLang-book-chapter09
//
//  Created by Eric Golovin on 10/26/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include "prog9-01.h"

void concat(char result[], const char str1[], int n1, const char str2[], int n2) {
    int i, j;
    
    // copy str1 to result
    
    for (i = 0; i < n1; i++) {
        result[i] = str1[i];
    }
    
    // copy str2 to result
    
    for (j = 0; j < n2; j++) {
        result[n1 + j] = str2[j];
    }
    
    result[i + j] = '\0';
}
