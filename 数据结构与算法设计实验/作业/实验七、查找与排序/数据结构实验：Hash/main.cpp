#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Hash(char str[5])
{
	int hash = 0;
	int i;
	for (i = 0; i < strlen(str); ++i) {
		hash = 26 * hash + (str[i] - 'a' + 1);
	}
	return hash % 18000;
}

int main()
{
	int sm[18000];
	int n, m, a;
	char str[5];
	scanf("%d%d", &n, &m);
	while (n--)
	{
		scanf("%s%d", &str, &a);
		sm[Hash(str)] = a;
	}
	while(m--)
	{
		scanf("%s", &str);
		printf("%d\n", sm[Hash(str)]);
	}
	return 0;
}