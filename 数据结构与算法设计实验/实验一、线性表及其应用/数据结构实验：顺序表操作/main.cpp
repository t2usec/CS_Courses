// TZOJ 5639

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;

typedef struct
{
	Elemtype *data;
	int length;
}SeqList;

//建表
void CreateSeqList(SeqList &L)
{
	L.data = (Elemtype *)malloc(200 * sizeof(Elemtype));
	L.length = 0;
}

//初始化
void InitSeqList(SeqList &L)
{
	L.length = 0;
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &L.data[L.length]);
		L.length++;
	}
}

//位置前插入元素
void InsertSeqList(SeqList &L, int pos, Elemtype x)
{
	if (pos < 0 || pos > L.length)
		return;
	for (int i = L.length; i > pos; i--)
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[pos] = x;
	L.length++;
}

//删除
void DeleteSeqList(SeqList &L, int pos)
{
	if (pos < 0 || pos >= L.length)
		return;
	for (int i = pos; i < L.length - 1; i++)
	{
		L.data[i] = L.data[i + 1];
	}
	L.length--;
}

//索引
void GetElemInSeqList(SeqList &L, int pos, Elemtype &x)
{
	x = L.data[pos];
}

//查找
int FindInSeqList(SeqList &L, Elemtype x)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x)
			return i;
	}
	return -1;
}

//逆置
void ReverseSeqList(SeqList &L)
{
	for (int i = 0; i < L.length / 2; i++)
	{
		Elemtype temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = temp;
	}
}