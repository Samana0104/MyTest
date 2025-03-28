#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>
using namespace std;

pair<vector<int>, vector<int>> separateOddsAndEvens(const vector<int>& arr)
{
	vector<int> odds, evens;
	for (int i : arr)
	{
		if (i % 2 == 1)
		{
			odds.push_back(i);
		}
		else
		{
			evens.push_back(i);
		}
	}

	return make_pair(odds, evens);
}

int main()
{
	vector<int> vecUnSplit = { 1,2,3,4,5,6,7,8,9,10 };
	auto [odds, evens] = separateOddsAndEvens(vecUnSplit);

	copy(odds.begin(), odds.end(), ostream_iterator<int>(cout, " "));
	copy(evens.begin(), evens.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
