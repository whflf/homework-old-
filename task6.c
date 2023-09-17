#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int primeNumbers(int number)
{
    for (int i = 0; i < number + 1; ++i) 
    {
        if (i > 1) 
        {
            bool primeNumber = true;
            int divisors = 0;
            for (int j = 2; j * j < i + 1; ++j) 
            {
                if (i % j == 0) 
                {
                    ++divisors;
                    break;
                }
            }
        if (divisors) 
        {
            primeNumber = false;
        }
            if (primeNumber) 
            {
                printf("%d\n", i);
            }
        }
    }
}

int main()
{
    int number = 0;
    printf("number = ");
    scanf_s("%d", &number);
    primeNumbers(number);
}
