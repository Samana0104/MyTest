#include <iostream>
#include <functional>
#include <string_view>
#include <algorithm>
using namespace std;

void PrintMessage(string_view message)
{
	cout << message << endl;
}

int main()
{
	string text("This is the haystack to search a needle in.");
	string toSearchFor("needle");
	
	boyer_moore_searcher searcher(cbegin(toSearchFor), cend(toSearchFor));
	auto result(search(cbegin(text), cend(text), searcher));

	if (result != cend(text))
		cout << "Found the needle." << endl;

	return 0;
}