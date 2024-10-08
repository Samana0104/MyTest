#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int _tmain()
{
	HANDLE test = CreateEvent(NULL, FALSE, TRUE, NULL);

	WaitForSingleObject(test, INFINITE);
	cout << " 되나??" << endl;
	WaitForSingleObject(test, INFINITE);


	cout << " 되나??" << endl;

	return 0;
}