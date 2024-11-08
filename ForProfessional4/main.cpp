#include <iostream>
#include <exception>
using namespace std;

void g() 
{
	throw invalid_argument("Some exception");
}

void f()
{
	try
	{
		g();
	}
	catch (const exception& e)
	{
		cout << "caught in f : " << e.what() << endl;
		throw e;
	}
}


int main()
{
	try
	{
		f();
	}
	catch (const invalid_argument& e)
	{
		cout << "invaliud_argument caught in main: " << e.what() << endl;
	}
	catch (const exception& e)
	{
		cout << "exception caught in main : " << e.what() << endl;
	}
	return 0;
}