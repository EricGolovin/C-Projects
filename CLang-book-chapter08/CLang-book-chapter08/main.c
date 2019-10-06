//
//  main.c
//  CLang-book-chapter08
//
//  Created by Eric Golovin on 06.10.2019.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>

void prog01() {
    struct date {
        int month;
        int day;
        int year;
    };
    
    struct date today;
    
    today.month = 9;
    today.day = 25;
    today.year = 2015;
    
    printf("Today's date is %i/%i/%.2i\n", today.month, today.day, today.year % 100);
}

int main(int argc, const char * argv[]) {
//    prog01();
    
    return 0;
}
