#include <stdio.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    
    if (l < n && arr[l] > arr[largest]) {
      printf("largestLeft-change: %i", largest);
      largest = l;
      printf(" -> %i\n", largest);
    }

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) {
      printf("largesRight-change: %i", largest);
      largest = r;
      printf(" -> %i\n", largest);
    }
  
    // If largest is not root 
    if (largest != i) { 
      printf("BeforeSwap: arr[%i] = %i arr[%i] = %i\n", i, arr[i], largest, arr[largest]);
      swap(&arr[i], &arr[largest]); 
      printf("AfterSwap: arr[%i] = %i arr[%i] = %i\n", i, arr[i], largest, arr[largest]);
      
      // Recursively heapify the affected sub-tree 
      heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) {
      printf("\n\nBuild heap: i = %i\n", i);
      heapify(arr, n, i);
    }

    // One by one extract an element from heap 
    for (int i= n - 1; i >= 0; i--) { 
      printf("\n\nExtract the element: i = %i\n", i);
        // Move current root to end 
        printf("BeforeMove arr[%i] = %i TO arr[0] = %i\n", i, arr[i], arr[0]);
        swap(&arr[0], &arr[i]); 
        printf("Move arr[i] = %i TO arr[0] = %i\n", i, arr[i], arr[0]);
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) {
      printf ("%i ", arr[i]);
    }
    printf("\n") ;
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
  
    heapSort(arr, 6); 
  
    printf("Sorted array is \n");
    printArray(arr, 6); 
} 
