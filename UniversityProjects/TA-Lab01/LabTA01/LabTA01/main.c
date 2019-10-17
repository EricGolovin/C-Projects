//
//  main.c
//  LabTA01
//
//  Created by Eric Golovin on 10/15/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>

#include "BubbleSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

int main() {
    // Methods to use later
    void bubbleSort(int arr[], int n);
    void printArray(int arr[], int size);
    void heapSort(int arr[], int n);
    void quickSort(int arr[], int low, int high);
    
    // Defining array
    int size = 99;
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
//    printf("Sorted array: \n");
//    heapSort(arr, size);
//    printArray(arr, size);
    
    // Quick Sort
    printf("Sorted array: \n");
    quickSort(arr, 0, size);
    printArray(arr, size);
    
    return 0;
}
