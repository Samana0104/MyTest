#include <Windows.h>
#include <iostream>
#include <tchar.h>
using namespace std;

#define MAX_THREADS (1024 * 10)

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	DWORD threadNum = (DWORD)lpParam;

	while (1)
	{
		wcout << L"thread nul :" << threadNum << endl;
		Sleep(5000);
	}
	return 0;
}

DWORD cntOfThread = 0;

int _tmain(int argc, TCHAR * argv[])
{
	int * a;

	ABC b;
	int d;

	DWORD  dwThreadID[MAX_THREADS];
	HANDLE hThread[MAX_THREADS];

	while (1)
	{
		if (true)
		{
			int a;
		}

		hThread[cntOfThread] =
		CreateThread(NULL, 1024 * 1024 * 10, ThreadProc, (LPVOID)cntOfThread, 0, &dwThreadID[cntOfThread]);

		if (hThread[cntOfThread] == NULL)
		{
			wcout << L"MAXIMUM THREAD NUMBER : " << cntOfThread << endl;
			break;
		}
		cntOfThread++;

		for (DWORD i = 0; i < cntOfThread; i++)
		{
			CloseHandle(hThread[i]);
		}
	}
	return 0;
}
