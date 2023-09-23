#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length = 0;
    printf("length = ");
    scanf_s("%d", &length);
    int *numbers = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        printf("numbers[%d] = ", i);
        scanf_s("%d", &numbers[i]);
    }
    int amountOfZeroes = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == 0)
        {
            amountOfZeroes += 1;
        }
    }
    printf("The amount of zero elements in the array is %d ", amountOfZeroes);
    free(numbers);
}
