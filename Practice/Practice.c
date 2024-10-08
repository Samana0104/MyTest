#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int** arr;
	int start = 1;
	int startPosX, startPosY;
	scanf("%d", &n);
	startPosX = (int)n / 2;
	startPosY = 0;
	arr = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * n);

	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d \n", arr[i][j]);

	while (start <= n * n)
	{
		arr[startPosY][startPosX] = start++;

		

		if (arr[(startPosY - 1 + n) % n][(startPosX + 1) % n] > 0)
		{
			startPosY = (startPosY + 1) % n;
		}
		else
		{
			startPosX = (startPosX + 1) % n;
			startPosY = (startPosY - 1 + n) % n;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
	return 0;
}

