//
//  prog7-15.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-15.h"

int convertedNumber[64];
long int numberToConvert;
int base;
int digit = 0;

void getTheNumberAndBase(void) {
    printf("Number to be converted? " );
    scanf_f("%li", &numberToConvert);

    printf("Base? ");
    scanf_f("%i", &base);

    if (base < 2 || base > 16) {
        printf("Bad base - must be bwtween 2 and 16 (base was set to 10th)\n");
        base = 10;
    }
}

void convertNumber(void) {
    do {
        convertedNumber[digit] = numberToConvert % base;
        digit++;
        numberToConvert /= base;
    } while (numberToConvert != 0);
}

void displayConvertedNumber(void) {
    const char baseDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int nextDigit;

    printf("Converted number = ");

    for (digit--; digit > 0; digit--) {
        nextDigit = convertedNumber[digit];
        printf("%c", baseDigits[nextDigit]);
    }

    printf("\n");
}
