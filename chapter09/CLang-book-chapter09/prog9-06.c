//
//  prog9-06.c
//  CLang-book-chapter09
//
//  Created by Eric Golovin on 10/26/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include "prog9-06.h"

void readLine(char buffer[]) {
    char character;
    int i = 0;
    
    do {
        character = getchar();
        buffer[i] = character;
        i++;
    } while (character != '\n');
    
    buffer[i - 1] = '\0';
}
