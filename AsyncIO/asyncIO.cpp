#include <Windows.h>
#include <string>
#include <string_view>
#include <iostream>
using namespace std;

DWORD AsyncLoad(wstring_view wsView)
{
	OVERLAPPED readOv = { };
	DWORD dwRead = 0;
	LARGE_INTEGER fileSize;

	HANDLE hReadFile = CreateFile(
		L"Text.txt",
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED | FILE_FLAG_WRITE_THROUGH,
		NULL);

	if (hReadFile != NULL)
	{
		GetFileSizeEx(hReadFile, &fileSize);
		std::string msg;
		msg.resize(fileSize.LowPart);
		DWORD dwReadSize;
		BOOL ret;
		bool bPending = false;

		ret = ReadFile(hReadFile, &msg[0], fileSize.LowPart, &dwReadSize, &readOv);
		if (ret == FALSE)
		{
			if (GetLastError() == ERROR_IO_PENDING)
			{
				cout << "로딩 중" << endl;
				bPending = true;
			}
		}
		if (ret == TRUE)
		{
			cout << "로딩 완료" << endl;
		}
		while (bPending)
		{
			BOOL bRet = GetOverlappedResult(hReadFile, &readOv, &dwRead, FALSE);

			if (bRet)
			{
				std::cout << "로딩완료" << std::endl;
				bPending = false;
			}
			else
			{
				if (GetLastError() == ERROR_IO_PENDING)
				{
					cout << "로딩 중" << endl;
					bPending = true;
				}
			}
		}
	}

	CloseHandle(hReadFile);
}


int main()
{

	HANDLE hWriteFile = CreateFile(
		L"Text.txt",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hWriteFile != NULL)
	{
		string msg;
		DWORD dwWriteSize;
		BOOL ret;
		ret = WriteFile(hWriteFile, &msg[0], sizeof(char)*msg.size(), &dwWriteSize, NULL);
		if (ret == TRUE)
		{
			cout << "출력 성공" << endl;
		}
		CloseHandle(hWriteFile);
	}

}