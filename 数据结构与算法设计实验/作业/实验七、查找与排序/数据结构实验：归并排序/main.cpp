#include <bits/stdc++.h>

using namespace std;

// 辅助数组，用于存放合并的序列
int temp[100000];

// 合并两个有序数组
void merge(int a[], int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	
	// 比较两个数组中的元素，并按照顺序放入辅助数组中
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}
	
	// 将剩余的元素放入辅助数组中
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= end) {
		temp[k++] = a[j++];
	}
	
	// 将辅助数组中的元素拷贝回原数组
	for (i = start; i <= end; i++) {
		a[i] = temp[i];
	}
}

void mergeSort(int a[], int start, int end)
{
	if(start >= end)
		return;
	int mid = (start + end )/2;
	mergeSort(a, start, mid);
	mergeSort(a, mid+1, end);
	merge(a, start, mid, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[100000], n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergeSort(a, 0, n-1);
	for(int i=0;i<n;i++)
	{
		if(i)
			cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
}