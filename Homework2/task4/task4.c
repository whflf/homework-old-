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

void halfQsort(int* array, int size)
{
    int index = 0;
    int firstElement = array[0];

    for (int i = 1; i < size; ++i) {
        if (array[i] < firstElement) {
            swap(&array[i], &array[index++]);
        }
    }
}

int *randArray()
{
    int* randomNumbers = (int*)malloc(20 * sizeof(int));

    if (randomNumbers == NULL) {
        int randomNumbers[1] = { -1 };
    }
    else {
        srand(time(NULL));
        for (int i = 0; i < 20; ++i) {
            randomNumbers[i] = rand();
        }
    }

    return randomNumbers;
}

bool testCorrectCase()
{
    int array1[5] = { 3, 1, 4, 5, 2 };
    int array2[5] = { 1, 2, 4, 5, 3 };

    halfQsort(array1, 5);

    if (memcmp(array1, array2, 5) == 0) {
        return true;
    }
    return false;
}

bool testBoundaryCase1()
{
    int array1[5] = { 1, 2, 3, 4, 5 };
    int array2[5] = { 1, 2, 3, 4, 5 };

    halfQsort(array1, 5);

    if (memcmp(array1, array2, 5) == 0) {
        return true;
    }
    return false;
}

bool testBoundaryCase2()
{
    int array1[5] = { 5, 4, 3, 2, 1 };
    int array2[5] = { 4, 3, 2, 1, 5 };

    halfQsort(array1, 5);

    if (memcmp(array1, array2, 5) == 0) {
        return true;
    }
    return false;
}

int main()
{
    if (!testCorrectCase() || !testBoundaryCase1() || !testBoundaryCase2()) {
        printf("Tests failed :(");
        return -1;
    }

    int *numbers = randArray();
    int memoryErrorArray[1] = { -1 };
    if (memcmp(numbers, memoryErrorArray, 1) == 0) {
        printf("~ Memory allocation has failed");
        return -1;
    }

    printf("Before conversion: ");
    for (int i = 0; i < 20; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    halfQsort(numbers, 20);
    printf("After conversion: ");
    for (int i = 0; i < 20; ++i) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
