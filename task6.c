#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main()
{
    int number;
    printf("number = ");
    scanf_s("%d", &number);
    for (int i = 0; i < number + 1; ++i) 
    {
        if (i > 1) 
        {
            bool primeNumber = false;
            for (int j = 2; j < round(sqrt(i)) + 1; ++j) 
            {
                if (i % j == 0) 
                {
                    primeNumber = true;
                    break;
                }
            }
            if (primeNumber == false) 
            {
                printf("%d\n", i);
            }
        }
    }
}
