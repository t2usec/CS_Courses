# 数据结构实验：归并排序

## 描述

给定n个整数，请使用归并排序算法对其进行从小到大排序。

部分代码已经给定，提交时请勿包含给定代码。

```cpp
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