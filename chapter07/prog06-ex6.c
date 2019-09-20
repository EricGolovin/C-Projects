//
// Created by Eric Golovin on 9/20/19.
//

#include <stdio.h>

int main(void) {
    int fibonacci01, fibonacci02, fibonacci03;

    fibonacci01 = 0; // by definition
    fibonacci02 = 1; // ditto

    for (int i = 0; i < 15; i++) {
        fibonacci03 = fibonacci01 + fibonacci02;
        fibonacci01 = fibonacci02;
        fibonacci02 = fibonacci03;

        printf("%i\n", fibonacci03);
    }

    return 0;
}