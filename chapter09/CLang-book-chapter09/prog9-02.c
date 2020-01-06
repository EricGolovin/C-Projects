//
//  prog9-02.c
//  CLang-book-chapter09
//
//  Created by Eric Golovin on 10/26/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include "prog9-02.h"

int stringLength(const char string[]) {
    int count = 0;
    
    while (string[count] != '\0') {
        count++;
    }
    return count;
}
