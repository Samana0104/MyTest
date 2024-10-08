#include <stdio.h>
#include "test.h"
extern void print();

int main()
{
	printf("%d\n", a);
	a++;
	printf("%d\n", a);
	print();
	return 0;
}
