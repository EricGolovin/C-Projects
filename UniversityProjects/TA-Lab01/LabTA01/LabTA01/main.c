//
//  main.c
//  LabTA01
//
//  Created by Eric Golovin on 10/15/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#include "BubbleSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

int main() {
    // Methods to use later
    clock_t t_start, t_end;
    double t_result;
    
    void bubbleSort(int arr[], int n);
    void printArray(int arr[], int size);
    void heapSort(int arr[], int n);
    void quickSort(int arr[], int low, int high);
    
    // Defining array
    
    int size = 9999;
    int arr[size];
    
    // Adding elements to array between 0 and 100
    for (int index = 0; index <= size; index++) {
        arr[index] = 0 + rand() % 100;
    }
    
    printf("UnSorted array: \n");
    printArray(arr, size);
    
//    Bubble Sort
//    bubbleSort(arr, size);
//    printf("Sorted array: \n");
//    printArray(arr, size);
    
    
//    Heap Sort
    printf("Sorted array: \n");
    heapSort(arr, size);
    printArray(arr, size);
    
    // Quick Sort
    
    t_start = clock();
    printf("Sorted array: \n");
    quickSort(arr, 0, size);
    printArray(arr, size);
    t_end = clock();

    t_result = (double) ((t_end - t_start) / CLOCKS_PER_SEC);
    
    printf("Timing: %f\n", t_result);
    
    return 0;
}
