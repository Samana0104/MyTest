#include <iostream>
#include <array>
#include <initializer_list>
#include <string>
using namespace std;

void func(char* str) { cout << "char* version" << endl; };
void func(int i) { cout << "int version" << endl; };
int main()
{
	func(NULL); // int ���
	func(nullptr); // char ���
	return 0;
}