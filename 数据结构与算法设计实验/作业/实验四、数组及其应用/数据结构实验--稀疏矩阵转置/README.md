# 数据结构实验--稀疏矩阵转置

## 描述

以三元组表作为存储结构实现稀疏矩阵的转置。

部分代码如下，请将代码补充完整。提交时不包括已给出的代码。

```c
void print(TSMatrix C)
{
	int i, j, n = 1;
	while (n <= C.tn)
	for (i = 1; i <= C.rn; i++)
	{
		for (j = 1; j <= C.cn; j++)
		if (C.elem[n].row == i&&C.elem[n].col == j)
		{
			printf("%4d", C.elem[n].data);
			n++;
		}
		else
			printf("%4d", 0);
		printf("\n");
	}
}
int  main()
{
	int i, j, m, n, k, t;
	TSMatrix *A, B;
	while (scanf("%d%d%d", &m, &n, &t) && t != 0)
	{
		A = creat(m, n, t);
		TransposeMatrix(A, &B);
		print(B);
		free(A);
	}
	return 0;
}
```

## 输入

输入数据有多组，每组输入数据第一行是三个整数m、n、t，分别代表稀疏矩阵的行数、列数和稀疏矩阵中非零元素的个数。接下来是t行，每行三个整数，分别代表非零元素所在的行、列和非零元素的值。t为0时输入结束。

非零元不超过20个。

## 输出

转置以后的稀疏矩阵，即n行m列的矩阵。

## 样例输入

```
3 4 3
1 1 5
2 3 7
3 1 2
```

## 样例输出

```
   5   0   2
   0   0   0
   0   7   0
   0   0   0
```

## 提示

稀疏矩阵以三元组表存储。