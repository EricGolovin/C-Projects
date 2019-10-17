//
//  QuickSort.c
//  LabTA01
//
//  Created by Eric Golovin on 10/16/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include "QuickSort.h"
#include "BubbleSort.h"

void swap(int* a, int* b);

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int partitioningIndex = partition(arr, low, high);
        
        quickSort(arr, low, partitioningIndex - 1);
        quickSort(arr, partitioningIndex + 1, high);
    }
}
