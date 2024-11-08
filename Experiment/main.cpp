#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <format>
using namespace std;

class MyClass
{
private:
	string m_str;
	string m_str2;

public:
	MyClass() = default;
	MyClass(const MyClass& src) = default;
	MyClass(string str) : m_str(move(str)) { }
	virtual ~MyClass() = default;

	MyClass& operator=(MyClass&& rhs) noexcept
	{
		if (this == &rhs)
			return *this;

		m_str = move(rhs.m_str);
		cout << format("Move operator= (m_str={})", m_str) << endl;
		return *this;
	}

	void setString(string str)
	{
		m_str = move(str);
	}

	const string& getString() const
	{
		return m_str;
	}
};

int main()
{
	vector<MyClass> vecSrc({ MyClass("a"), MyClass("b"), MyClass("c") });
	vector<MyClass> vecDst(vecSrc.size());

	move(begin(vecSrc), end(vecSrc), begin(vecDst));
	for (const auto& c : vecDst)
	{
		cout << c.getString() << " ";
	}
	return 0;
}