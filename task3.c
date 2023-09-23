#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int number1 = 0;
    int number2 = 0;
    printf("number1 = ");
    scanf_s("%d", &number1);
    printf("number2 = ");
    scanf_s("%d", &number2);
    int dividend = number1;
    int divisor = number2;
    int answer = 0;
    if (number2 == 0)
    {
        printf("Zero division is prohibited ");
        return -1;
    }
    number1 = abs(number1);
    number2 = abs(number2);
    if (number1 % number2 == 0) {
        printf("%d / %d = %d", dividend, divisor, dividend / divisor);
        return;
    }
    while (number1 > number2)
    {
        number1 -= number2;
        answer += 1;
    }
    if (dividend < 0 && divisor > 0)
    {
        answer = -answer - 1;
    }
    if (dividend < 0 && divisor < 0)
    {
        ++answer;
    }
    else if (dividend > 0 && divisor < 0) 
    {
        answer = -answer;
    }
    printf("%d / %d = %d", dividend, divisor, answer);
}
