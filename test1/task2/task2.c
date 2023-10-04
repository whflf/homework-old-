#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* value1, int* value2)
{
    int value1Prev = *value1;
    *value1 = *value2;
    *value2 = value1Prev;
}

int bubbleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        if (array[i] < 0 || (i != size - 1 && array[i + 1] < 0))
        {
            return -1;
        }
        int j = 0;
        if ((size - 1) % 2 == 0) {
            j = size - 1;
        }
        else {
            j = size - 2;
        }
        for (j; j > i; j -= 2)
        {
            if (array[j - 2] > array[j])
            {
                swap(&array[j - 2], &array[j]);
            }
        }
    }
    return 0;
}

bool testCorrectCase()
{
    int unsortedArray[5] = { 2, 5, 4, 3, 1 };
    int sortedArray[5] = { 1, 5, 2, 3, 4 };

    bubbleSort(unsortedArray, 5);

    if (memcmp(unsortedArray, sortedArray, 5) == 0)
    {
        return true;
    }
    return false;
}

bool testIncorrectCase()
{
    int unsortedArray[5] = { 2, -5, 4, 3, 1 };

    if (bubbleSort(unsortedArray, 5) == -1) {
        return true;
    }
    return false;
}

bool testBoundaryCase()
{
    int unsortedArray[5] = { 1, 5, 2, 3, 4 };
    int sortedArray[5] = { 1, 5, 2, 3, 4 };

    bubbleSort(unsortedArray, 5);

    if (memcmp(unsortedArray, sortedArray, 5) == 0)
    {
        return true;
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
    for (int i = 0; i < length; ++i)
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

    return 0;
}
