#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

int compare(const int* a, const int* b)
{
    return *a - *b;
}

int* randArray(int n, int rangeMax, int rangeMin)
{
    int* randomNumbers = (int*)malloc(n * sizeof(int));

    if (randomNumbers == NULL) {
        int randomNumbers[1] = { -1 };
    }
    else {
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            randomNumbers[i] = ((double)rand() / RAND_MAX) * (rangeMax - rangeMin) + rangeMin;
        }
    }

    return randomNumbers;
}

int binarySearch(int array[], int first, int last, int number)
{

    while (first <= last) {
        int middle = first + (last - first) / 2;
        if (array[middle] == number) {
            return middle;
        }
        if (array[middle] < number) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
        }
    }

    return -1;
}

bool testCorrectCase()
{
    int testArray[5] = { 4, 9, 1, 0, 3 };
    return binarySearch(testArray, 0, 4, 0) != -1;
}

bool testIncorrectCase()
{
    int testArray[5] = { 4, 9, 1, 0, 3 };
    return binarySearch(testArray, 0, 4, 5) == -1;
}

int main() {
    int n = 0;
    int k = 0;

    printf("> n = ");
    scanf_s("%d", &n);

    int* numbers = randArray(n, 0, 100);
    printf("Array of %d numbers: ", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    qsort(numbers, n, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("> k = ");
    scanf_s("%d", &k);

    for (int i = 0; i < k; ++i) {
        int key = ((double)rand() / RAND_MAX) * 50;
        int index = binarySearch(numbers, 0, n - 1, key);
        if (index > -1) {
            printf("%d has an index of %d\n", key, index + 1);
        }
        else {
            printf("%d is not in the array\n", key);
        }
    }

    return 0;
}
