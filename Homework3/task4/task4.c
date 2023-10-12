#include <stdio.h>
#include <stdlib.h>

int scanfSafetyChecks(int scanfFieldsFilled) {
    char extraInput;

    if (!scanfFieldsFilled) { 
        printf("!! Wrong input. Please enter an integer but nothing else !!");
        return 1;
    }
    if (scanf_s("%c", &extraInput) != EOF && extraInput != '\n') { 
        printf("!! Extra characters found in input. Please enter an integer and nothing else !!");
        return 2;
    }
    return 0;
}

int compareIntegers(const int* a, const int* b) {
    return *a - *b;
}

void printMostOccurredElement(int numbers[], int size) {
    if (!size) { 
        printf("~ Got an empty array");
        return;
    }

    qsort(numbers, size, sizeof(int), compareIntegers); 

    int mostOccurredElement = numbers[0];
    int currentElement = numbers[0];
    int currentCount = 1;
    int maxCount = 1;

    for (int i = 1; i < size; ++i) { 
        
        if (numbers[i] == currentElement) { 
            ++currentCount; 
        }
        else { 
            currentElement = numbers[i]; 
            currentCount = 1; 
        }

        if (currentCount > maxCount) { 
            maxCount = currentCount; 
            mostOccurredElement = currentElement; 
        }
    }

    printf("* Most occurred integer: %d", mostOccurredElement);
}

int main() {
    int size = 0;

    printf("> Enter array size: ");

    if (scanfSafetyChecks(scanf_s("%d", &size))) {
        return 1;
    }

    if (size < 0) {
        printf("!! Array size can not be negative !!");
        return 1;
    }

    int* numbers = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("> a[%d] = ", i);

        if (scanfSafetyChecks(scanf_s("%d", &numbers[i]))) {
            return 1;
        }
    }

    printMostOccurredElement(numbers, size);
    free(numbers);

    return 0;
}
