#include <iostream>
#include <Windows.h>
using namespace std;

void __cdecl Test1(int c)
{
	int a, b;

	return;
}

void __stdcall Test2(int c)
{
	int a, b;

	return;
}

void __fastcall Test3(int c)
{
	int a, b;

	return;
}

int main()
{
	Test1(1);
	Test2(2);
	Test3(3);
	return 0;
}
