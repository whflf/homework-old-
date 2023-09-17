#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int parenthesisBalance(char string[])
{
    int count = 0;
    const stringLength = strlen(string);
    for (int i = 0; i < stringLength; i++)
    {
        if (string[i] == '(')
        {
            ++count;
        }
        if (string[i] == ')')
        {
            --count;
            if (count < 0)
            {
                break;
            }
        }
    }
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char string[LENGTH] = { '\0' };
    printf("string = ");
    fgets(string, LENGTH, stdin);
    printf("%s", parenthesisBalance(string) ? "ok" : "not ok");
    return 0;
}
