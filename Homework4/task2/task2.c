#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

#define FILE_OPEN_ERROR -1
#define TESTS_FAILURE_ERROR 1

int readArray(int* array) 
{
    FILE* file;
    if (fopen_s(&file, "array.txt", "r") != 0) 
    {
        return FILE_OPEN_ERROR;
    }
    int linesRead = 0;

    while (!feof(file)) 
    {
        const int readBytes = fscanf_s(file, "%d", &array[linesRead]);
        if (readBytes < 0) 
        {
            break;
        }
        ++linesRead;
    }

    fclose(file);
    return linesRead;
}

int getMostOccurredElement(int numbers[], int size) 
{
    if (!size) 
    {
        printf("~ Got an empty array");
        return;
    }

    quicksort(numbers, 0, size - 1);

    int mostOccurredElement = numbers[0];
    int currentElement = numbers[0];
    int currentCount = 1;
    int maxCount = 1;

    for (int i = 1; i < size; ++i) 
    {

        if (numbers[i] == currentElement) 
        {
            ++currentCount;
        }
        else 
        {
            currentElement = numbers[i];
            currentCount = 1;
        }

        if (currentCount > maxCount) 
        {
            maxCount = currentCount;
            mostOccurredElement = currentElement;
        }
    }

    return mostOccurredElement;
}

bool testCorrectCase()
{
    int array[10] = { -1, -5, 1, 7, 7, 5, 7, -2, 7, 5 };
    return getMostOccurredElement(array, 10) == 7;
}

bool testBoundaryCase()
{
    int array[10] = { -3, 9, 2, -1, 5, -8, 3, 0, 7, -4 };
    return getMostOccurredElement(array, 10) == -8;
}

int main() 
{
    if (!testCorrectCase() || !testBoundaryCase()) 
    {
        printf("~ Tests failed");
        return TESTS_FAILURE_ERROR;
    }

    int* numbers = malloc(100 * sizeof(int));

    const int size = readArray(numbers);
    for (int i = 0; i < size; ++i) 
    {
        printf("%d ", numbers[i]);
    }
    printf_s("\narray size: %d\n", size);

    int mostOccurredElement = getMostOccurredElement(numbers, size);
    printf("* Most occurred integer: %d", mostOccurredElement);

    free(numbers);
    return 0;
}

