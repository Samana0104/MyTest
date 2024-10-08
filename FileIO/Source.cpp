#include <iostream>
#include <tchar.h>
#include <Windows.h>
using namespace std;

#define STRING_LEN 100
TCHAR fileData[] = L"abcdefghijklmnopqrstuvwxyz";

int _tmain()
{
	TCHAR fileName[] = L"abcd.dat";
	TCHAR readBuf[STRING_LEN];

	HANDLE hFile;
	DWORD numOfByteWritten = 0;
	DWORD dwPtr = 0;

	hFile = CreateFile(
		fileName,
		GENERIC_WRITE,
		0,
		0,
		CREATE_ALWAYS,
		0,
		0);

	WriteFile(hFile, fileData, sizeof(fileData), &numOfByteWritten, NULL);
	CloseHandle(hFile);

	hFile = CreateFile(
		fileName, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	ReadFile(hFile, readBuf, sizeof(readBuf), &numOfByteWritten, NULL);

	wcout << readBuf << endl;

	dwPtr = SetFilePointer(hFile, sizeof(TCHAR) * 4, NULL, FILE_BEGIN);
	if (dwPtr == INVALID_SET_FILE_POINTER)
	{
		wcout << "SetFilePointer Error" << endl;
		return -1;
	}

	ReadFile(hFile, readBuf, sizeof(readBuf), &numOfByteWritten, NULL);
	wcout << readBuf << endl;

	return 0;
}