#include <stdio.h>
#include <conio.h>


int arraySwap(int array[], int m, int n)
{
    for (int i = 0; i < m / 2 + 1; i++)
    {
        if (m % 2 == 1 && i == m / 2)
        {
            break;
        }
        int auxiliaryVariable = array[m - i - 1];
        array[m - i - 1] = array[i];
        array[i] = auxiliaryVariable;
    }
    int j = 0;
    for (int i = m; i < m + n / 2 + 1; i++)
    {
        if (n % 2 == 1 && i == m + n / 2)
        {
            break;
        }
        int auxiliaryVariable = array[m + n - j - 1];
        array[m + n - j - 1] = array[i];
        array[i] = auxiliaryVariable;
        j += 1;
    }
    for (int i = 0; i < m + n; i++)
    {
        if ((m + n) % 2 == 1 && i == (m + n) / 2)
        {
            break;
        }
        int auxiliaryVariable = array[m + n - i - 1];
        array[m + n - i - 1] = array[i];
        array[i] = auxiliaryVariable;
    }
    return array[m + n];
}


int main()
{
    int length = 0;
    int m, n;
    printf("length = ");
    scanf_s("%d", &length);
    int* numbers;
    numbers = (int*)malloc(length * sizeof(int) * 10);
    for (int i = 0; i < length; i++)
    {
        printf("numbers[%d] = ", i);
        scanf_s("%d", &numbers[i]);
    }
    printf("m = ");
    scanf_s("%d", &m);
    printf("length = ");
    scanf_s("%d", &n);
    arraySwap(numbers, m, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", numbers[i]);
    free(numbers);
    return 0;
}
