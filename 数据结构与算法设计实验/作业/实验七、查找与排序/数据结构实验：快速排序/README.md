# 数据结构实验：快速排序

## 描述

给定n个整数，请使用递归快速排序算法对其进行从小到大排序。

快速排序的算法步骤如下：

1.挑选基准值：从数列中挑出一个元素，称为 “基准”（pivot） ；

2.分割：重新排序序列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（与基准值相等的数可以到任何一边）。在这个分割结束之后，对基准值的排序就已经完成；

3.递归排序子序列：递归地将小于基准值元素的子序列和大于基准值元素的子序列排序。

![](https://www.tzcoder.cn/acmhome/ueditor/jsp/upload/image/20210628/1624861455741093832.gif)

```cpp
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
```

## 输入

第一行为正整数n（n<=100000），第二行为n个整数。

## 输出

输出排序后的n个整数，以空格分开。

## 样例输入

```
5
1 3 2 4 5
```

## 样例输出

```
1 2 3 4 5
```