#include <iostream>
#include <>
#include <tchar.h>
#include <Windows.h>
using namespace std;

#define BUF_SIZE 1024
int CommToClient(HANDLE);

int _tmain(int argc, TCHAR* argv[])
{
	LPCTSTR pipeName = L"\\\\.\\pipe\\simple_pipe";
	HANDLE hPipe;

	while (true)
	{
		hPipe = CreateNamedPipe(
			pipeName,
			PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
			PIPE_UNLIMITED_INSTANCES,
			BUF_SIZE / 2,
			BUF_SIZE / 2,
			20000, NULL);

		if (hPipe == INVALID_HANDLE_VALUE)
		{
			wcout << L"CreateNamedPipe failed" << endl;
			return -1;
		}

		bool isSuccess;
		isSuccess = ConnectNamedPipe(hPipe, NULL) ? true : (GetLastError() == ERROR_PIPE_CONNECTED);

		if (isSuccess)
			CommToClient(hPipe);
		else
			CloseHandle(hPipe);
	}
	return 0;
}

int CommToClient(HANDLE hPipe)
{
	TCHAR fileName[MAX_PATH];
	TCHAR dataBuf[BUF_SIZE];
	bool isSuccess;
	DWORD fileNameSize;

	isSuccess = ReadFile(
		hPipe, fileName, MAX_PATH * sizeof(TCHAR), &fileNameSize, NULL);

	if (!isSuccess || fileNameSize == 0)
	{
		wcout << L"Pipe read message error" << endl;
		return -1;
	}

	FILE* filePtr = _topen(fileName, _O_RDONLY);
}
