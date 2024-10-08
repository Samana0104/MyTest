#include <iostream>
#include <tchar.h>
#include <Windows.h>
using namespace std;

#define WORK_MAX 10000
#define THREAD_MAX 50

using WORK = void(*)(void);

DWORD AddWorkToPool(WORK work);
WORK GetWorkFromPool();
DWORD MakeThreadToPool(DWORD numOfThread);
void WorkerThreadFunction(LPVOID pParam);

struct WorkerThread
{
	HANDLE hThread;
	DWORD idThread;
};

struct ThreadPool
{
	WORK workList[WORK_MAX];

	WorkerThread workerThreadList[THREAD_MAX];
	HANDLE workerEveneList[THREAD_MAX];

	DWORD idxOfCurrentWork;
	DWORD idxOfLastAddedWork;

	DWORD threadIdx;
};

ThreadPool gThreadPool;
static HANDLE mutex = NULL;

void InitMutex()
{
	mutex = CreateMutex(NULL, false, NULL);
}


void DeInitMutex()
{
	bool ret = CloseHandle(mutex);
}

void AcquireMutex()
{
	DWORD ret = WaitForSingleObject(mutex, INFINITE);

	if (ret == WAIT_FAILED)
		wcout << L"Error occur" << endl;
}

void ReleaseMutex()
{
	bool ret = ReleaseMutex(mutex);
	if (ret == 0)
		wcout << L"Error occur" << endl;
}

DWORD AddWorkToPool(WORK work)
{
	AcquireMutex();
	if (gThreadPool.idxOfLastAddedWork >= WORK_MAX)
	{
		wcout << L"AddWorkToPool fail" << endl;
		return NULL;
	}

	gThreadPool.workList[gThreadPool.idxOfLastAddedWork++] = work;

	for (DWORD i = 0; i < gThreadPool.threadIdx; i++)
		SetEvent(gThreadPool.workerEveneList[i]);

	ReleaseMutex();
	return 1;
}

WORK GetWorkFromPool()
{
	WORK work = NULL;

	AcquireMutex();

	if (!(gThreadPool.idxOfCurrentWork < gThreadPool.idxOfLastAddedWork))
	{
		ReleaseMutex();
		return NULL;
	}

	work = gThreadPool.workList[gThreadPool.idxOfCurrentWork++];
	ReleaseMutex();

	return work;
}

DWORD MakeThreadToPool(DWORD numOfThread)
{
	InitMutex();
	DWORD capacity = WORK_MAX - (gThreadPool.threadIdx);

	if (capacity < numOfThread)
		numOfThread = capacity;

	for (DWORD i = 0; i < numOfThread; i++)
	{
		DWORD idThread;
		HANDLE hThread;

		gThreadPool.workerEveneList[gThreadPool.threadIdx] = CreateEvent(NULL, false, false, NULL);

		hThread = CreateThread(
			NULL, 0,
			(LPTHREAD_START_ROUTINE)WorkerThreadFunction,
			(LPVOID)gThreadPool.threadIdx,
			0, &idThread
		);


		gThreadPool.workerThreadList[gThreadPool.threadIdx].hThread = hThread;
		gThreadPool.workerThreadList[gThreadPool.threadIdx].idThread = idThread;

		gThreadPool.threadIdx++;
	}

	return numOfThread;
}

void WorkerThreadFunction(LPVOID pParam)
{
	WORK workFunction;
	HANDLE event = gThreadPool.workerEveneList[(DWORD)pParam];

	while (1)
	{
		workFunction = GetWorkFromPool();
		if (workFunction == NULL)
		{
			WaitForSingleObject(event, INFINITE);
			continue;
		}

		workFunction();
	}
}

void TestFunction()
{
	static int i = 0;
	i++;

	wcout << L"Good Test -- " << i << L" : Processing thread : % --" << GetCurrentThreadId() << endl << endl;
}

int _tmain(int argc, TCHAR** argv)
{
	MakeThreadToPool(3);

	for (int i = 0; i < 100; i++)
	{
		AddWorkToPool(TestFunction);
	}

	Sleep(50000);
	return 0;
}
