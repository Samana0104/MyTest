#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	int key;
	int j;
	for (int i = 1; i < 6; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}

	for (int i : arr)
	{
		cout << i << endl;
	}
	return 0;
}