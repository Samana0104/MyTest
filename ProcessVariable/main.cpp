#include <iostream>
#include <tchar.h>
#include <Windows.h>
using namespace std;

int _tmain(int argc, TCHAR * argv[])
{
	SetEnvironmentVariable(L"Good", L"Moring");

	Sleep(100000);
	return 0;
}