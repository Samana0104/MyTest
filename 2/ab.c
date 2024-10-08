#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int hanoi(char a, char b, char c, int num)
{
	int sum = 0;
	if (num == 0)
	{
		//printf("[%d¹ø][%c -> %c]\n", num, a, c);
		//sum++;
		//return sum;
		return 0;
	}

	sum += hanoi(a, c, b, num - 1);
	printf("[%d¹ø][%c -> %c]\n", num, a, c);
	sum++;
	sum += hanoi(b, a, c, num - 1);

	return sum;
}


int main()
{
	printf("%d\n", hanoi('A', 'B', 'C',3));
	return 0;
}