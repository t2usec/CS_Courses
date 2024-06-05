# 数据结构实验：Hash

## 描述

给出字符串以及对应的值，并根据字符串进行查询。

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
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
```

## 输入

输入数据的第一行为n和m。

接下来n行，每行一个字符串（3个小写字母组成）和对应的值。

接下来m行，每行一个字符串，请查询该字符串所对应的值（字符串一定在该列表中）。

## 输出

输出每个字符串所对应的值。

## 样例输入

```
3 3
abc 1
def 4
bcd 5
abc
bcd
def
```

## 样例输出

```
1
5
4
```