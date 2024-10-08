#include <iostream>
#include <vector>
#include <string_view>
#include <ranges>
using namespace std;


void PrintRange(string_view message, auto& range)
{
	cout << message;
	for (const auto& value : range)
		cout << value << " ";

	cout << endl;
}

int main()
{
	vector values({ 1,2,3,4,5,6,7,8,9,10 });
	PrintRange("Original sequence: ", values);

	auto result1(values | views::filter([](const auto& value) { return value % 2 == 0; }));
	PrintRange("Only even values: ", result1);

	auto result2(values | views::transform([](const auto& value) {return value * 2.0; }));
	PrintRange("Values doubled : ", result2);
	
	auto result3(result2 | views::drop(2));
	PrintRange("First two dropped: ", result3);

	auto result4(result3 | views::reverse);
	PrintRange("Sequence reversed : ", result4);
	
	PrintRange("saigo ", values);
	cout << typeid(result4).name() << endl;
	return 0;
}