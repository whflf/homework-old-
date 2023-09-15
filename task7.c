#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LENGTH 100

int main()
{
    char string[LENGTH], string1[LENGTH];
    printf("s = ");
    fgets(string, LENGTH, stdin);
    printf("s1 = ");
    fgets(string1, LENGTH, stdin);
    int index = 0;
    int count = 0;
    for (int i = 0; i < strlen(string); i++) 
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
    printf("%d", count);
    return 0;
}
