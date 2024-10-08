#include <iostream>
#include <vector>
#include <forward_list>
#include <span>
#include <array>
using namespace std;

void Print(span<int> values)
{
	for (const auto& value : values)
	{
		cout << value << " ";
	}
}

int main()
{
	vector<int> a({ 1,2,3,4,5,7,44 });
	array<int, 7> bc{ 1,2,3,4,5,6,7 };
	Print(a);
	Print(bc);
	return 0;
}
