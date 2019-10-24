//
//  main.cpp
//  DM-Lab01
//
//  Created by Eric Golovin on 10/25/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include <iostream>

using namespace std;

int implication(int a, int b) {
    if (a == b) {
        return 1;
    } else if (a > b) {
        return 0;
    } else if (a < b) {
        return 1;
    } else {
        return NULL;
    }
}

int main(int argc, const char * argv[]) {
    int a, b, c, d;

    printf("|a|\t|b|\t|c|\t|d|\n");

    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            for (c = 0; c <= 1; c++) {
                for (d = 0; d <= 1; d++) {
                    printf("|%i|\t|%i|\t|%i|\t|%i|\t\t|%i|\n", a, b, c, d, implication(a && b && !d && c, ((a && !c) && (!a && b && d)) && !(a && c && d)));
                }
            }
        }
    }
}
