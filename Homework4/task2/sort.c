#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int* value1, int* value2)
{
    int value1Prev = *value1;
    *value1 = *value2;
    *value2 = value1Prev;
}

void insertionSort(int* array, int low, int high)
{
    for (int i = low; i <= high - 1; ++i) {
        int j = i - 1;
        while (array[j + 1] < array[j]) {
            swap(&array[j + 1], &array[j]);
            --j;
        }
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            ++i;
            if (i != j) {
                swap(&array[i], &array[j]);
            }
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quicksort(int array[], int low, int high)
{
    if (low < high) {
        int partitionIndex = partition(array, low, high);
        if ((partitionIndex - low) >= 10) {
            quicksort(array, low, partitionIndex);
        }
        else {
            insertionSort(array, low, partitionIndex);
        }
        if ((high - partitionIndex) >= 10) {
            quicksort(array, partitionIndex + 1, high);
        }
        else {
            insertionSort(array, partitionIndex, high + 1);
        }
    }
}