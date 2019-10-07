//
//  main.c
//  CLang-book-chapter08
//
//  Created by Eric Golovin on 06.10.2019.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "prog04.h"
#include "prog05.h"

struct date {
    int month;
    int day;
    int year;
};
struct time {
    int hour;
    int minutes;
    int seconds;
};

struct month {
    int numberOfDays;
    char name[3];
};

void prog01() {
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

void prog05() {
    struct time timeUpdate(struct time now);
    struct time currentTime, nextTime;
    
    printf("Enter the time (hh:mm:ss): ");
    scanf("%i %i %i", &currentTime.hour, &currentTime.minutes, &currentTime.seconds);
    
    nextTime = timeUpdate(currentTime);
    
    printf("Updated time is %i:%i:%i\n", nextTime.hour, nextTime.minutes, nextTime.seconds);
}

void prog06() {
    struct time timeUpdate(struct time now);
    struct time testTimes[5] = { {}, {}, {}, {}, {} };
    
    for (int i = 0; i < 5; i++) {
        int sixtyRand = 1 + rand() % 55;
        int twentyRand = 1 + rand() % 24;
        
        testTimes[i].hour = twentyRand;
        testTimes[i].minutes = sixtyRand;
        testTimes[i].seconds = sixtyRand;
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Time is %.2i:%.2i:%.2i", testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
        
        testTimes[i] = timeUpdate(testTimes[i]);
        
        printf(" ...one second later it's %.2i:%.2i:%.2i\n", testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
    }
}

void prog07() {
    const struct month months[12] = {{ 31, {'J', 'a', 'n'}}, { 28, {'F', 'e', 'b'}}, { 31, {'M', 'a', 'r'}}, { 30, {'A', 'p', 'r'}}, { 31, {'M', 'a', 'y'}}, { 30, {'J', 'u', 'n'}}, { 31, {'J', 'u', 'l'}}, { 31, {'A', 'u', 'g'}}, { 30, {'S', 'e', 'p'}}, { 31, {'O', 'c', 't'}}, { 30, {'N', 'o', 'v'}}, { 31, {'D', 'e', 'c'}}};
    
    printf("Month    Number of Days\n");
    printf("-----    --------------\n");
    
    for (int i = 0; i < 12; i++) {
        printf(" %c%c%c           %i\n", months[i].name[0], months[i].name[1], months[i].name[2], months[i].numberOfDays);
    }
    
}

int main(int argc, const char * argv[]) {
//    prog01();
//    prog02();
//    prog04();
//    prog05();
//    prog06();
    prog07();
    
    return 0;
}
