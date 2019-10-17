//
//  BubbleSort.c
//  LabTA01
//
//  Created by Eric Golovin on 10/15/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "BubbleSort.h"

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int indexUp = 0; indexUp < n - 1; indexUp++) {
        for (int indexDown = 0; indexDown < n - indexUp - 1; indexDown++) {
            if (arr[indexDown] > arr[indexDown + 1]) {
                swap(&arr[indexDown], &arr[indexDown + 1]);
            }
        }
    }
    
    
    
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

