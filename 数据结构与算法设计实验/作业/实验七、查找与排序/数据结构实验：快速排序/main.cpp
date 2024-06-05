#include <bits/stdc++.h>

using namespace std;

int Partition(int a[], int low, int high) {
	int pivot = a[high]; // 选择最后一个元素作为 pivot
	int i = low - 1; // 分区操作的关键是 i 和 j 两个指针
	
	for (int j = low; j <= high - 1; j++) {
		// 当前元素小于或等于 pivot 时，交换到前面去
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1; // 返回 pivot 的正确位置
}

void QSort(int a[], int low, int high)
{
	int piv = Partition(a, low, high);
	if(low<piv-1)
		QSort(a, low, piv-1);
	if(piv+1<high)
		QSort(a, piv+1, high);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int a[100000], n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	QSort(a, 0, n-1);
	cout<<a[0];
	for(int i=1;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	cout<<endl;
	return 0;
}