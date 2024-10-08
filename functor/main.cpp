#include <iostream>
#include <unordered_set>
#include <functional>
using namespace std;

class Hasher
{
public:
	size_t operator()(string_view str) const
	{
		return hash<string_view>()(str);
	}
};
int main()
{
	unordered_set<string, Hasher, equal_to<>> mySet;
	mySet.insert("Key");
	mySet.insert("Key2");
	mySet.insert("Key3");
	auto i1(mySet.find("Key"));
	cout << typeid(i1).name() << endl;
	auto i2(mySet.find("Key"));
}