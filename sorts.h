#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    int minIndex = start;
    int i;
    for (i = start + 1; i < stop; i++){
        if (array[i] < array[minIndex])
        {
            minIndex = i;
        }
        
    }
    return minIndex;
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    int i;
    for (i = 0; i < size - 1; i++) {
        int minIndex = findMinimum(array, i, size);
        // Swap the smallest element with the first element in the unsorted part of the array
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
        if (print == 1) {
            int j;
            for ( j = 0; j < size; j++) {
                printf("%d ", array[j]);
            }
            printf("\n");
        }
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    int i;

    for (i = 1; i < size; i++)
    {
        int k;
        for ( k = i; k >= 1; k--)
        {
            if (array[k] < array[k-1])
            {
                int temp = array[k];
                array[k] = array[k-1];
                array[k-1] = temp;
            }
        }
        
        if (print == 1) {
            int j;
            for ( j = 0; j < size; j++) {
                printf("%d ", array[j]);
            }
            printf("\n");
        }
    }
 
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    /**
    for (unsigned int i = 0; i < size - 1; i++)
    {
        // iterate over the remaining unsorted elements
        for (unsigned int j = 0; j < size - i - 1; j++)
        {
            // swap adjacent elements if they are in the wrong order
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }

        if (print == 1) {
            int j;
            for ( j = 0; j < size; j++) {
                printf("%d ", array[j]);
            }
            printf("\n");
        }
    }
    */

}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    int i, j, k;

    // Copy data to temp arrays
    for (i = l; i <= r; i++)
    {
        temp[i] = arr[i];
    }

    i = l; // Initial index of first subarray
    j = m + 1; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    // Merge the temp arrays back into arr[l..r]
    while (i <= m && j <= r)
    {
        if (temp[i] <= temp[j])
        {
            arr[k] = temp[i];
            i++;
        }
        else
        {
            arr[k] = temp[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of left subarray
    while (i <= m)
    {
        arr[k] = temp[i];
        k++;
        i++;
    }

    // Copy the remaining elements of right subarray
    while (j <= r)
    {
        arr[k] = temp[j];
        k++;
        j++;
    }

}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
   if (arr == NULL){
    return;
   }

   if (r > 1) {
    int m = (l + r)/2;
    merge_sort(arr, temp, l, m);
    merge_sort(arr, temp, m + 1, r);
    merge(arr, temp, l, m, r);
   }
   return;
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif