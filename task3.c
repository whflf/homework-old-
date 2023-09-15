#include <stdio.h>
#include <stdbool.h>

main()
{
    int number1 = 0;
    int number2 = 0;
    printf("number1 = ");
    scanf_s("%d", &number1);
    printf("number2 = ");
    scanf_s("%d", &number2);
    int answer = 0;
    bool flag = false;
    if (number1 < 0 ^ number2 < 0)
    {
        flag = true;
    }
    if (number2 == 0)
    {
        printf("Zero division is prohibited ");
        return -1;
    }
    if (number1 < 0)
    {
        number1 = -number1;
    }
    if (number2 < 0)
    {
        number2 = -number2;
    }
    while (number1 > number2)
    {
        number1 -= number2;
        answer += 1;
    }
    if (flag == true)
    {
        answer = -answer;
    }
    printf("%d / %d = %d", number1, number2, answer);
}
