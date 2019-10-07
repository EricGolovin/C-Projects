//
//  prog05.c
//  CLang-book-chapter08
//
//  Created by Eric Golovin on 07.10.2019.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog05.h"

struct time {
    int hour;
    int minutes;
    int seconds;
};

struct time timeUpdate(struct time now) {
    now.seconds++;
    if (now.seconds == 60) { // next minute
        now.seconds = 0;
        now.minutes++;
        
        if (now.minutes == 60) { // next hour
            now.minutes = 0;
            now.hour++;
            
            if (now.hour == 24) { // midnight
                now.hour = 0;
            }
        }
    }
    return now;
}
