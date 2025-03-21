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
		cout << "설치 C" << endl;
	}
	~C()
	{
		cout << "해제C " << endl;
	}
};
struct Node
{
	C m_c;
	std::shared_ptr<Node> childNode;

	Node()
	{
		cout << "노드 생성" << endl;
	}
	~Node()
	{
		cout << "노드 해제" << endl;
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
		cout << "클래스 생성" << endl;
	}

	~Test()
	{
		cout << "클래스 해제" << endl;
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