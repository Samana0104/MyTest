#include <iostream>
#include <vector>
using namespace std;

class MoveableClass
{
public:
	int a = 3;
public:
	MoveableClass()
	{
		cout << "Default constructor" << endl;
	}

	MoveableClass(const MoveableClass& src)
	{
		cout << "copy Constructor" << endl;
	}

	MoveableClass(MoveableClass&& src) noexcept
	{
		cout << "Move constructor" << endl;
	}

	MoveableClass& operator=(const MoveableClass&& rhs)
	{
		cout << "Copy assignment operator" << endl;
		return *this;
	}

	MoveableClass& operator=(MoveableClass&& rhs) noexcept
	{
		cout << "Move assignment operator*" << endl;
		return *this;
	}
};

int main()
{
	vector<MoveableClass> vecSource;
	MoveableClass mc;
	vecSource.push_back(mc);
	vecSource.push_back(mc);
	vector<MoveableClass> vecTwo(make_move_iterator(begin(vecSource)), make_move_iterator(end(vecSource)));
	return 0;
}