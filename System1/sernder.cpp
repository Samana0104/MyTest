#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;

#define SLOT_NAME _T("\\\\.\\mailslot\\mailbox")
int _tmain(int argc, TCHAR* argv[])
{
	
	HANDLE hMailSlot;
	TCHAR message[50];
	DWORD bytesWritten;

	hMailSlot = CreateFile(SLOT_NAME, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hMailSlot == INVALID_HANDLE_VALUE)
	{
		_fputts(_T("Unable to create mailslot!\n"), stdout);
		return 1;

	}

	while (true)
	{
		_fputts(_T("My cmd>"), stdout);
		_fgetts(message, sizeof(message) / sizeof(TCHAR), stdin);

		if (!WriteFile(hMailSlot, message, _tcslen(message) * sizeof(TCHAR), &bytesWritten, NULL))
		{
			_fputts(_T("Unable to write!"), stdout);
			CloseHandle(hMailSlot);
			return 1;
		}

		if (!_tcscmp((message), _T("exit")))
		{
			_fputts(_T("Good Bye!"), stdout);
			break;
		}
	}
	CloseHandle(hMailSlot);
	return 0;
}
