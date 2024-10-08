#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tchar.h>
#include <Windows.h>
using namespace std;

int _tmain(int argc, TCHAR** argv)
{
	TCHAR str[2];

	__try
	{
		_tcscpy(str, L"ABCDEFTRHFDLJKSHJLKFLKF~");
		_tprintf(L"%s \n", str);
	}
	__finally
	{
		_tprintf(L"__finally block\n");
	}

	return 0;
}