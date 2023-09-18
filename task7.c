#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int substringsCount(char string[], char string1[])
{
    int index = 0;
    int count = 0;
    const stringLength = strlen(string);
    for (int i = 0; i < stringLength; i++)
    {
        if (string[i] == string1[index])
        {
            index += 1;
            if (index == strlen(string1) - 1)
            {
                index = 0;
                count += 1;
            }
        }
        else if (index != 0)
        {
            index = 0;
        }
    }
    return count;
}

int main()
{
    char string[LENGTH] = { '\0' };
    char string1[LENGTH] = { '\0' };
    printf("s = ");
    fgets(string, LENGTH, stdin);
    printf("s1 = ");
    fgets(string1, LENGTH, stdin);
    printf("S includes S1 %d times", substringsCount(string, string1));
    return 0;
}
