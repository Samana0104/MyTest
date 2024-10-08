#include <cstdio>
#include <tchar.h>
#include <Windows.h>
#include <process.h>

#define NUM_OF_GATE 6

LONG gTotalCount = 0;

HANDLE hMutex;

void IncreaseCount()
{
	WaitForSingleObject(hMutex, INFINITE);

	gTotalCount++;
	ReleaseMutex(hMutex);
}

unsigned int WINAPI ThreadProc(LPVOID lpParam)
{
	for (DWORD i = 0; i < 1000; i++)
	{
		IncreaseCount();
	}
	return 0;
}

int _tmain(int argc, TCHAR** argv)
{
	DWORD dwThreadIDs[NUM_OF_GATE];
	HANDLE hThreads[NUM_OF_GATE];

	hMutex = CreateMutexW(NULL, FALSE, NULL);
	if (hMutex == NULL)
	{
		_tprintf(L"CreateMutex error");
	}

	for (DWORD i = 0; i < NUM_OF_GATE; i++)
	{
		hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, NULL, CREATE_SUSPENDED, (unsigned*)&dwThreadIDs[i]);

		if (hThreads[i] == NULL)
		{
			_tprintf(L"Thread creation fault! \n");
			return -1;
		}
	}

	for (DWORD i = 0; i < NUM_OF_GATE; i++)
	{
		ResumeThread(hThreads[i]);
	}

	WaitForMultipleObjects(NUM_OF_GATE, hThreads, TRUE, INFINITE);

	_tprintf(L"total count : %d \n", gTotalCount);


	for (DWORD i = 0; i < NUM_OF_GATE; i++)
	{
		CloseHandle(hThreads[i]);
	}

	CloseHandle(hMutex);

	return 0;
}


