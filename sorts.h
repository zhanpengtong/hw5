#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include <stdio.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    int minIndex = start; // set a defalut min for begin, change it later.
    int i;
    for (i = start + 1; i < stop; i++){
        if (array[minIndex] <= array[i])
        { //check the index if is the smaller one.
        } else{
            minIndex = i; // if not will change it to the smaller one.
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
    if (size == 0) {
        return;
    }
    int i;
    for (i = 0; i < size - 1; i++) {
        int min = findMinimum(array, i, size); // use findMinimum method to find the min in current array index.
        swap(&array[min], &array[i]); // swap the smaller one to the cueernt index.
        if (print == 1) {
            printIntArray(array, size);
        }
    }
    if (print == 1) {
        printIntArray(array, size);
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
    if (size == 0) {
        return;
    }

    int i;

    for (i = 1; i < size; i++)
    {
        // looking array form the begin to end.
        int k;
        for ( k = i; k >= 1; k--)
        {
            if (array[k] < array[k-1])
            {
                //swap the index if current is smaller than front index.
                int temp = array[k];
                array[k] = array[k-1];
                array[k-1] = temp;
            }
        }
        
        if (print == 1) {
            printIntArray(array, size);
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
   int i, j;
   // use i, j to make two for loop.
   for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - 1; j++) {
        if (array[j] > array[j + 1]) {
            swap(&array[j], &array[j + 1]); // if the cueernt index is great than the after the current index.
        }
    }

    if (print == 1) {
        printIntArray(array, size);
    }
   }

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

    if (l > m || m + 1 > r)
        return;

    int i, a, b;
    a = l;
    b = m + 1;

    for (i = l; i <= r; i++) {
        // conbain two subarray(index beginng to mid, mid to end).
        // put the small one frist in to temp[array].
        // temp star with index l and end with r.
        if (a <= m && b <= r) {
            if (arr[a] < arr[b]) {
                temp[i] = arr[a];
                a += 1;
            } else {
                temp[i] = arr[b];
                b += 1;
            }
        } else if (a <= m) {
            temp[i] = arr[a];
            a += 1;
        } else if (b <= r) {
            temp[i] = arr[b];
            b += 1;
        }
    }
    int k;
    for (k = l; k <= r; k++)
    {
        // use a for loop copy all the sort int from temp to the arr.
        arr[k] = temp[k];
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
    if (r > 1){
        // make the cueern arr to two subarray.(cut form mid)
        int m = (l + r) / 2;
        merge_sort(arr, temp, l, m); // cut the first subarray to two subarray again.
        merge_sort(arr, temp, m + 1, r); // cut the second subarray to two subarray.
        merge(arr, temp, l, m, r); // put the arr to sort.
    }
    return;
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (size == 0) {
        return;
    }
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size); // make a temp empty array have same size with the array.
    merge_sort(array, temp, 0, size - 1); give the array and temp to sort.
    free(temp); // get the temp free.
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