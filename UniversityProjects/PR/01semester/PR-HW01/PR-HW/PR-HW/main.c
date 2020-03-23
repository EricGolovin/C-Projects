//
//  main.c
//  PR-HW
//
//  Created by Eric Golovin on 10/21/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include <stdio.h>

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
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int array[6] = { 1, -4, 3, 9, -8, 7 };
    
    bubbleSort(array, 6);
    
    printArray(array, 6);
    
    return 0;
}
