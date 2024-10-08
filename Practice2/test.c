#include <stdio.h>
 
int partition (int arr[], int p, int r){
    int low, high;
    int pivot = arr[p]; // pivot �� ����
 
    low = p + 1; // low �� pivot�� �ٷ� ���� ��ġ��������
    high = r; // high�� ���޵� ������
 
    while(low <= high){
        while(arr[low] < pivot) low++; // pivot ���� ���� ���� ���ö����� �̵�
        while(arr[high] > pivot) high--; // pivot ���� ū ���� ���ö����� �̵�
 
        if (low <= high){ // low�� high �� �ߴܵ� ������ ���� ��ġ�� ������ ������ �ƴ϶��
            int temp = arr[low];    // low �� high �� �� ����
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
 
    // �ǹ��� high ��ġ ��ȯ
    int temp = arr[p];
    arr[p] = arr[high];
    arr[high] = temp;
 
    return high; // �ǹ� ��ġ ��ȯ
 
}
 
void quick_sort(int arr[], int left, int right){
    if (left < right){
        int pivot = partition(arr, left, right);
 
        quick_sort(arr, left, pivot-1); // �ǹ��� �������� ���� �迭 ����
        quick_sort(arr, pivot+1, right); // �ǹ� �������� ������ �迭 ����
    }
}
int main (){
    int arr [] = {9,8,7,6,5,4,3,2,1};
 
    quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
 
    for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++){
        printf("%d ", arr[i]);
    }
}