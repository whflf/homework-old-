#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 100

int palindromCheck(const char string[])
{
    char stringWithoutSpaces[LENGTH] = { '\0' };

    int i = 0;
    int j = 0;
    int spacesCount = 0;

    while (string[i] != '\0') {
        if (string[i] != ' ' && string[i] != '\n') {
            stringWithoutSpaces[j] = string[i];
            ++j;
        }
        else if (string[i] == ' ') {
            ++spacesCount;
        }
        else if (string[i] == '\n') {
            break;
        }
        ++i;
    }

    int rightIndex = i - spacesCount - 1;
    int leftIndex = 0;

    for (int i = 0; i <= rightIndex / 2; ++i) {
        if (leftIndex == rightIndex) {
            break;
        }
        if (stringWithoutSpaces[leftIndex] != stringWithoutSpaces[rightIndex]) {
            return 0;
        }
        ++leftIndex;
        --rightIndex;
    }
    
    return 1;
}

bool testCorrectCase1()
{
    const char testString = "abccba";
    return palindromCheck(testString) == 1;
}

bool testCorrectCase2()
{
    const char testString = "aB c cB a";
    return palindromCheck(testString) == 1;
}

bool testIncorrectCase()
{
    const char testString = "abcCBA";
    return palindromCheck(testString) == 0;
}

int main()
{
    if (!testCorrectCase1() || !testCorrectCase2() || !testIncorrectCase()) {
        printf("Tests failed :(");
        return -1;
    }

    char string[LENGTH] = { '\0' };

    printf("> Enter the string (up to 100 symbols): ");
    fgets(string, LENGTH, stdin);

    printf("%s", palindromCheck(string) ? "The string is a palindrom" : "The string isn't a palindrom");
    return 0;
}
