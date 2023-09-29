#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void swap(int* value1, int* value2)
{
    int value1Prev = *value1;
    *value1 = *value2;
    *value2 = value1Prev;
}

int arrayMax(int* array, int size)
{
    int maximum = 0;
    for (int i = 0; i < size; ++i)
    {
        maximum = max(maximum, array[i]);
    }
    return maximum;
}

int bubbleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] < 0) 
        {
            return -1;
        }
        for (int j = (size - 1); j > i; --j)
        {
            if (array[j - 1] > array[j])
            {
                swap(&array[j - 1], &array[j]);
            }
        }
    }
    return 0;
}

int countingSort(int* array, int size)
{
    const int maxNumber = arrayMax(array, size);
    int* countingArray = (int*)malloc((maxNumber * 2) * sizeof(*array));
    memset(countingArray, 0, sizeof(*array) * (maxNumber + 1));
    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) 
        {
            return -1;
        }
        ++countingArray[array[i]];
    }
    int index = 0;
    for (int i = 0; i < maxNumber + 1; ++i) {
        for (int j = 0; j < countingArray[i]; ++j)
        {
            array[index++] = i;
        }
    }
    free(countingArray);
    return 0;
}

bool testCorrectCase()
{
    int unsortedArray[5] = { 2, 5, 4, 3, 1 };
    int sortedArray[5] = { 1, 2, 3, 4, 5 };
    bubbleSort(unsortedArray, 5);
    if (memcmp(unsortedArray, sortedArray, 5) == 0) 
    {
        int unsortedArray[5] = { 2, 5, 4, 3, 1 };
        countingSort(unsortedArray, 5);
        if (memcmp(unsortedArray, sortedArray, 5) == 0) 
        {
            return true;
        }
        return false;
    }
    return false;
}

bool testIncorrectCase()
{
    int unsortedArray[5] = { -2, 5, -4, 3, 1 };
    if (bubbleSort(unsortedArray, 5) == -1 && countingSort(unsortedArray, 5) == -1) 
    {
        return true;
    }
    return false;
}

bool testBoundaryCase()
{
    int unsortedArray[5] = { 1, 2, 3, 4, 5 };
    int sortedArray[5] = { 1, 2, 3, 4, 5 };
    bubbleSort(unsortedArray, 5);
    if (memcmp(unsortedArray, sortedArray, 5) == 0)
    {
        int unsortedArray[5] = { 1, 2, 3, 4, 5 };
        countingSort(unsortedArray, 5);
        if (memcmp(unsortedArray, sortedArray, 5) == 0)
        {
            return true;
        }
        return false;
    }
    return false;
}

int main()
{
    if (!testCorrectCase() || !testIncorrectCase() || !testBoundaryCase())
    {
        printf("~ Tests failed");
        return -1;
    }

    int length = 0;
    printf("> Enter the length: ");

    int errorCode = 0;
    errorCode = scanf_s("%d", &length);
    if (errorCode == 0)
    {
        printf("!! Please enter an integer !!");
        return -1;
    }

    int* numbers = (int*)malloc(length * sizeof(int));
    if (numbers == NULL) 
    {
        printf("Memory allocation failed :(");
    }

    printf("> Enter the elements of the array (>= 0):\n");
    for (int i = 0; i < length; i++)
    {
        printf("a[%d] = ", i);
        errorCode = scanf_s("%d", &numbers[i]);
        if (errorCode == 0) 
        {
            printf("!! Enter only integers >= 0 !!");
            return -1;
        }
    }

    errorCode = bubbleSort(numbers, length);
    if (errorCode != 0) 
    {
        printf("!! Elements cannot be negative !! ");
        return -1;
    }
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);

    printf("\n");
    srand(345);
    int randomNumbers[100000] = { 0 };
    for (int i = 0; i < 100000; ++i)
    {
        randomNumbers[i] = rand();
    }

    clock_t start = clock();
    errorCode = bubbleSort(randomNumbers, 100000);
    if (errorCode != 0) 
    {
        printf("An error occured :(");
        return -1;
    }

    clock_t stop = clock();
    double duration = (stop - start) / CLOCKS_PER_SEC;
    printf("Bubble sort required %2.10f seconds\n ", duration);

    srand(346);
    int randomNumbers2[100000] = { 0 };
    for (int i = 0; i < 100000; ++i)
    {
        randomNumbers2[i] = rand();
    }

    start = clock();
    errorCode = countingSort(randomNumbers2, 100000);
    if (errorCode != 0)
    {
        printf("An error occured :(");
        return -1;
    }
    for (int i = 99999; i > 99899; --i) {
        printf("%d ", randomNumbers2[i]);
    }
    stop = clock();
    duration = (stop - start) / CLOCKS_PER_SEC;
    printf("Counting sort required %2.10f seconds ", duration);

    return 0;
}