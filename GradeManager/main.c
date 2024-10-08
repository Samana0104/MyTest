#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Grade.h"

int main()
{
	Grade grade = { "Å×½ºÆ®", 'A', 20 };

	LoadGrade(&grade);
	PrintGrade(&grade);
	return 0;
}