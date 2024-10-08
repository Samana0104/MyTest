#include <iostream>
using namespace std;

int partition(int A[], int start, int end);

void QuickSort(int A[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(A, start, end);
		QuickSort(A, start, pivot-1);
		QuickSort(A, pivot+1, end);
	}
} 

int partition(int A[], int start, int end)
{
	int pivot = start;
	int	i = start+1;
	int j = end;
	int temp = 0;
	while (i <= j)
	{
		while (i <= j && A[pivot] >= A[i])
			i++;

		while (i <= j && A[pivot] <= A[j])
			j--;

		if (i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	temp = A[pivot];
	A[pivot] = A[j];
	A[j] = temp;

	return j;
}

int main()
{
	int A[] = { 5,5,7,8,9 };

	QuickSort(A, 0, 4);
	cout << "Test" << endl;
	for (int idx : A)
		cout << idx << endl;
	return 0;
}
