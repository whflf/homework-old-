#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define LENGTH 100

int main()
{
	int sums[28] = { 0 };
	for (int i = 0; i < 1000; i++) 
	{
		int digit1 = i % 10;
		int digit2 = 0;
		int digit3 = 0;
		if (i >= 10) 
		{
			digit2 = i / 10;
		}
		if (i >= 100) 
		{
			digit3 = i / 100;
			digit2 = i / 10 % 10;
		}
		sums[digit1 + digit2 + digit3] += 1;
	}
	int happyTickets = 0;
	for (int i = 0; i < 28; i++) 
	{
		happyTickets += sums[i] * sums[i];
	}
	printf("%d", happyTickets);
}
