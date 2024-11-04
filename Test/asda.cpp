#include <iostream>
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF
		| _CRTDBG_LEAK_CHECK_DF
		| _CRTDBG_DELAY_FREE_MEM_DF);
	cout << fixed;
	cout.precision(10);
	cout << (double)4 / 13 * 9 << endl;
	int* a = new int;
	*a = 3;

	_CrtCheckMemory();
	return 0;
}