#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <process.h>
using namespace std;

unsigned int WINAPI ThreadProc(LPVOID lpParam)
{
	while (true)
	{
		_tprintf(L"Running State! \n");
		Sleep(5000);
	}
	return 0;
}

int _tmain(int argc, TCHAR* argv[])
{
	DWORD dwThreadID;
	HANDLE hThread;
	DWORD susCnt;

	hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, NULL, CREATE_SUSPENDED, (unsigned*)&dwThreadID);

	if (hThread == NULL)
		wcout << L"Thread creation fault \n" << endl;

	susCnt = ResumeThread(hThread);
	wcout << L"suspend count : " << susCnt << endl;
	Sleep(5000);

	susCnt = SuspendThread(hThread);
	wcout << L"suspend count : " << susCnt << endl;
	Sleep(5000);

	susCnt = SuspendThread(hThread);
	wcout << L"suspend count : " << susCnt << endl;
	Sleep(5000);

	susCnt = ResumeThread(hThread);
	wcout << L"suspend count : " << susCnt << endl;
	Sleep(5000);

	susCnt = ResumeThread(hThread);
	wcout << L"suspend count : " << susCnt << endl;
	Sleep(5000);

	WaitForSingleObject(hThread, INFINITE);
	return 0;
}