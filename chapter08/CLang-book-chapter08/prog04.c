//
//  prog04.c
//  CLang-book-chapter08
//
//  Created by Eric Golovin on 06.10.2019.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog04.h"

struct date {
    int month;
    int day;
    int year;
};

// Function to calculate tomorrow's date

struct date dateUpdate(struct date today) {
    struct date tomorrow;
    int numberOfDays(struct date d);
    
    if (today.day != numberOfDays(today)) {
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
    
    return tomorrow;
}

// Function to find the number of days in a month

int numberOfDays(struct date d) {
    int days;
    _Bool isLeapYear(struct date d);
    const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (isLeapYear(d) && d.month == 2) {
        days = 29;
    } else {
        days = daysPerMonth[d.month - 1];
    }
    
    return days;
}

// Function to determine if it's a leap year

_Bool isLeapYear(struct date d) {
    
    _Bool leapYearFlag;
    
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
        leapYearFlag = 1; // It's a leap year
    } else {
        leapYearFlag = 0; // Not a leap year
    }
    
    return leapYearFlag;
}
