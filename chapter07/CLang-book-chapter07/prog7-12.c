//
//  prog7-12.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "prog7-12.h"

void sort(int a[], int n, int order) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            switch (order) {
                case 0:
                    if (a[i] > a[j]) {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                    break;
                case 1:
                    if (a[i] < a[j]) {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                    break;
                default:
                    break;
            }
        }

    }
}
