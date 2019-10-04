//
//  prog7-ex09.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-ex09.h"
#include "prog7-6.h"

int lcm(int u, int v) {
    int gcd(int u, int v);
    
    if (u >= 0 && v >= 0) {
        return u * v / gcd(u, v);
    } else {
        return 0;
    }
}
