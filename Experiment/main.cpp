#include <memory>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <format>
#include <string_view>
using namespace std;

class C
{
public:
	C()
	{
		cout << "��ġ C" << endl;
	}
	~C()
	{
		cout << "����C " << endl;
	}
};
struct Node
{
	C m_c;
	std::shared_ptr<Node> childNode;

	Node()
	{
		cout << "��� ����" << endl;
	}
	~Node()
	{
		cout << "��� ����" << endl;
	}
};

class Test
{
private:
	std::shared_ptr<Node> test;

public:
	Test()
	{
		test = make_shared<Node>();
		test->childNode = make_shared<Node>();
		cout << "Ŭ���� ����" << endl;
	}

	~Test()
	{
		cout << "Ŭ���� ����" << endl;
	}
};

class A
{
private:
	std::shared_ptr<Test> m_test;

public:
	A()
	{
		m_test = make_shared<Test>();
	}
};

int main()
{
	std::shared_ptr<A> test = make_shared<A>();

	return 0;
}