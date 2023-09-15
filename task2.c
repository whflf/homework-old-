#include <stdio.h>
#include <stdlib.h>

main()
{
    int number1 = 0;
    int number2 = 0;
    printf("Enter the 1st number: ");
    scanf_s("%d", &number1);
    printf("Enter the 2nd number: ");
    scanf_s("%d", &number2); 
    number1 = number1 + number2;
    number2 = number1 - number2;
    number1 = number1 - number2;
    printf("The 1st number is %d, the 2nd number is %d ", number1, number2);
}
