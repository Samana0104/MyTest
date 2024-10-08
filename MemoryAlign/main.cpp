#include <iostream>
using namespace std;

int main()
{
	__declspec(align(32)) int arr1[6] = { 0, };
	typedef __declspec(align(8)) struct { int a; } M_align;
	M_align* arr4 = (M_align*)_mm_malloc(sizeof(M_align) * 4, 16);
	cout << sizeof(M_align) << " , " << sizeof(M_align) << " , "<<__alignof(M_align)<<endl;
	for (int i=0; i<4; i++)
	{
		cout << &arr4[i] << endl;
	}
	return 0;
}