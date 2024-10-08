#include <iostream>
#include <tchar.h>
#include "SwapDLL.h"
using namespace std;
#pragma comment(lib, "DLLTest.lib")

int _tmain(int argc, TCHAR* argv[])
{
	wcout << "result Add : " << Add(5, 3) << endl;
	wcout << "result Mul : " << Mul(5.0, 3.0) << endl;
	wcout << "result Div : " << Div(5.0, 3.0) << endl;
	return 0;
}