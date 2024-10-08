#include <iostream>
using namespace std;

void Heapify(int A[], int k, int n);

void BuildHeap(int A[], int n)
{
	for (int i = static_cast<int>(n / 2); i >= 1; i--)
		Heapify(A, i, n);
}

void Heapify(int A[], int k, int n)
{
	int left = k * 2;
	int right = k * 2 + 1;
	int smaller = 0;
	int temp = 0;

	if (right <= n)
	{
		if (A[left] < A[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= n)
	{
		smaller = left;
	}
	else
	{
		return;
	}

	if (A[smaller] < A[k])
	{
		temp = A[smaller];
		A[smaller] = A[k];
		A[k] = temp;
//		Heapify(A, smaller, n);
	}
}

void heapSort(int A[], int n)
{
	BuildHeap(A, n);
	int temp = 0;

	for (int i = n; i >= 1; i--)
	{
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;

		cout << temp << " , ";
		Heapify(A, 1, i - 1);
	}
}

int main()
{

	int A[7] = { 0, 7, 9, 4, 8, 6, 3 };


	heapSort(A, 6);
	return 0;
}