//
//  prog9-07.c
//  CLang-book-chapter09
//
//  Created by Eric Golovin on 10/26/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include "prog9-07.h"

_Bool alphabetic(const char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

int countWords(const char string[]) {
    int i, wordCount = 0;
    _Bool lookingForWord = 1, alphabetic(const char c);
    
    for (i = 0; string[i] != '\0'; i++) {
        if (alphabetic(string[i])) {
            if (lookingForWord) {
                wordCount++;
                lookingForWord = 0;
            }
        } else {
            lookingForWord = 1;
        }
    }
    
    return wordCount;
}
