#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int _tmain()
{
	HANDLE test = CreateEvent(NULL, FALSE, TRUE, NULL);

	WaitForSingleObject(test, INFINITE);
	cout << " �ǳ�??" << endl;
	WaitForSingleObject(test, INFINITE);


	cout << " �ǳ�??" << endl;

	return 0;
}