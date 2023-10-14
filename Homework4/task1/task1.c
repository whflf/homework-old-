#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define TESTS_FAILURE_ERROR -1
#define WRONG_SCANF_FIELDS_ERROR 1;
#define EXTRA_INPUT_ERROR 2;

int scanfSafetyChecks(int scanfFieldsFilled)
{
    char* extraInput = { '\0' };

    if (!scanfFieldsFilled) {
        printf("!! Неверный ввод. Пожалуйста, введите целое число !!");
        return WRONG_SCANF_FIELDS_ERROR;
    }
    if (scanf_s("%c", &extraInput) != EOF && extraInput != '\n') {
        printf("!! Пожалуйста, введите целое число без лишних знаков !!");
        return EXTRA_INPUT_ERROR;
    }
    return 0;
}

int *binary(int x)
{
    if (x < 0) {
        x = (1 << 8) + x;
    }

    int* binaryNumber = (int*)calloc(8, sizeof(int));
    if (binaryNumber == NULL) {
        return -1;
    }

    int i = 0;

    int bit = 0b10000000;

    for (int j = 0; j < 8; ++j) {
        if (x & bit) {
            binaryNumber[i] = 1;
        }
        bit = bit >> 1;
        ++i;
    }

    return binaryNumber;
}

int* binarySum(int x[], int y[]) {
    int* binarySum = (int*)calloc(9, sizeof(int));
    if (binarySum == NULL) {
        return -1;
    }

    int additionalDigit = 0;

    for (int i = 7; i >= 0; --i) {
        if (x[i] + y[i] + additionalDigit > 1) {
            if (x[i] + y[i] + additionalDigit == 3) {
                binarySum[i + 1] = 1;
            }
            additionalDigit = 1;
        }
        else {
            binarySum[i + 1] = x[i] + y[i] + additionalDigit;
            additionalDigit = 0;
        }
    }
    if (x[0] + y[0] > 1) {
        binarySum[0] = 1;
    }

    return binarySum;
}

int decimal(int x[]) {
    int decimalNumber = 0;

    for (int i = 0; i < 9; ++i) {
        int degree = 8 - i;
        decimalNumber += (1 << degree) * x[i];
    }

    return decimalNumber;
}

bool testCorrectCase()
{
    int x = 5;
    int y = 8;
    int* sumOfXAndY = binarySum(binary(x), binary(y));
    int correctSum[9] = { 0, 0, 0, 0, 0, 1, 1, 0, 1 };
    return memcmp(sumOfXAndY, correctSum, 5) == 0;
}

int main()
{
    if (!testCorrectCase()) {
        printf("~Tests failed");
        return TESTS_FAILURE_ERROR;
    }

    setlocale(LC_ALL, "ru-RU");

    int x = 0;
    int y = 0;

    printf("> Введите х: ");
    if (scanfSafetyChecks(scanf_s("%d", &x))) {
        return 1;
    }

    printf("> Введите у: ");
    if (scanfSafetyChecks(scanf_s("%d", &y))) {
        return 1;
    }

    int *binaryX = binary(x);
    int *binaryY = binary(y);

    printf("Двоичное представление числа х: ");
    for (int i = 0; i < 8; ++i) {
        printf("%d", binaryX[i]);
    }
    printf("\nДвоичное представление числа у: ");
    for (int i = 0; i < 8; ++i) {
        printf("%d", binaryY[i]);
    }

    printf("\nДвоичное представление суммы чисел х и у: ");
    int* sumOfXAndY = binarySum(binaryX, binaryY);
    for (int i = 0; i < 9; ++i) {
        printf("%d", sumOfXAndY[i]);
    }

    printf("\nДесятичное представление суммы чисел х и у: %d", decimal(sumOfXAndY));

    return 0;
}
