#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int row;
	int col;
	int data;
} Triple;

typedef struct {
	Triple elem[MAX_SIZE];
	int rn;
	int cn;
	int tn;
} TSMatrix;

TSMatrix* creat(int m, int n, int t) {
	TSMatrix *A = (TSMatrix *)malloc(sizeof(TSMatrix));
	A->rn = m;
	A->cn = n;
	A->tn = t;
	int i;
	for (i = 1; i <= t; i++) {
		scanf("%d%d%d", &A->elem[i].row, &A->elem[i].col, &A->elem[i].data);
	}
	return A;
}

void TransposeMatrix(TSMatrix *A, TSMatrix *B) {
	B->rn = A->cn;
	B->cn = A->rn;
	B->tn = A->tn;
	int q = 1;
	int col;
	for (col = 1; col <= A->cn; col++) {
		int p;
		for (p = 1; p <= A->tn; p++) {
			if (A->elem[p].col == col) {
				B->elem[q].row = A->elem[p].col;
				B->elem[q].col = A->elem[p].row;
				B->elem[q].data = A->elem[p].data;
				q++;
			}
		}
	}
}

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