#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
main()
{
	int var1, var2;
	printf("var1 = ");
	scanf_s("%d", &var1);
	printf("var2 = ");
	scanf_s("%d", &var2); 
	int answer = 0;
	bool flag = false;
	if (var1 < 0 ^ var2 < 0)
	{
		flag = true;
	}
	if (var2 == 0)
	{
		printf("Zero division is prohibited ");
		return -1;
	}
	if (var1 < 0)
	{
		var1 = -var1;
	}
	if (var2 < 0)
	{
		var2 = -var2;
	}
	while (var1 > var2)
	{
		var1 -= var2;
		answer += 1;
	}
	if (flag == true)
	{
		answer = -answer;
	}
	printf("%d ", answer);
}
