#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int primeNumber(int number)
{
    int divisors = 0;
    for (int j = 2; j * j < number + 1; ++j)
    {
        if (number % j == 0)
        {
            ++divisors;
            break;
        }
    }
    return (divisors == 0);
}

int main()
{
    int number = 0;
    printf("number = ");
    scanf_s("%d", &number);
    printf("Prime numbers up to %d:\n", number);
    if (number < 2) 
    {
        printf("no numbers");
    }
    for (int i = 2; i < number + 1; ++i) 
    {
        if (primeNumber(i))
        {
            printf("%d\n", i);
        }
    }
}
