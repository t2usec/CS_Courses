#include <stdio.h>
#include <stdlib.h>

void Zip(int a[][100], int n, int *b) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			b[i * (i + 1) / 2 + j] = a[i][j];
		}
	}
}

int Index(int i, int j) {
	i--;
	j--;
	if (i <= j) {
		return j * (j + 1) / 2 + i;
	} else {
		return i * (i + 1) / 2 + j;
	}
}

int main()
{
	int n, i, j, a[100][100];
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d", &a[i][j]);
	}
	int *b = (int*)malloc(sizeof(int)*n*(n+1)/2);
	Zip(a, n, b);
	while(scanf("%d%d", &i, &j)!=EOF)
	{
		printf("%d\n", b[Index(i, j)]);
	}
	free(b);
	return 0;
}