#define _COMPLING_DLL_CALCULATOR
#include "SwapDLL.h"

LIBSPEC int Add(int a, int b)
{
	return a + b;
}

LIBSPEC int Min(int a, int b)
{
	return a - b;
}

LIBSPEC double Div(double a, double b)
{
	return a / b;
}

LIBSPEC double Mul(double a, double b)
{
	return a * b;
}
