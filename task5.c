#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#define LENGTH 100

int main()
{
	char string[LENGTH];
	printf("string = ");
	fgets(string, LENGTH, stdin);
	int count = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '(')
		{
			count += 1;
		}
		if (string[i] == ')')
		{
			count -= 1;
			if (count < 0)
			{
				break;
			}
		}
	}
	if (count == 0) 
	{
		printf("ok");
	}
	else 
	{
		printf("not ok");
	}
	return 0;
}
