//
//  main.c
//  CLang-book-chapter08
//
//  Created by Eric Golovin on 06.10.2019.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>

#include "prog04.h"

struct date {
    int month;
    int day;
    int year;
};

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

void prog02() {
    struct date {
        int month;
        int day;
        int year;
    };
    
    struct date today, tomorrow;
    
    const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &today.month, &today.day, &today.year);
    
    if (today.day != daysPerMonth[today.month - 1]) {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    } else if (today.month == 12) { // end of year
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    } else {
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    
    printf("Tomorrow's date is %i/%i/%.2i.\n", tomorrow.month, tomorrow.day, tomorrow.year % 100);
}

void prog04() {
    struct date dateUpdate(struct date today);
    struct date thisDay, nextDay;
    
    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i%i%i", &thisDay.month, &thisDay.day, &thisDay.year);
    
    nextDay = dateUpdate(thisDay);
    
    printf("Tomorrow's date is %i/%i/%.2i.\n", nextDay.month, nextDay.day, nextDay.year % 100);
}

int main(int argc, const char * argv[]) {
//    prog01();
//    prog02();
//    prog04();
    
    return 0;
}
