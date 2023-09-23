#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int substringsCount(const char string[], const char string1[])
{
    int index = 0;
    int count = 0;
    const int stringLength = strlen(string);
    const int string1Length = strlen(string1);
    for (int i = 0; i < stringLength; ++i)
    {
        if (string[i] == string1[0])
        {
            int substringFlag = 1;
            for (int j = 1; j < string1Length - 1; ++j) 
            {
                if (string[i + j] != string1[j]) 
                {
                    substringFlag = 0;
                    break;
                }
            }
            if (substringFlag == 1) 
            {
                ++count;
            }
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
