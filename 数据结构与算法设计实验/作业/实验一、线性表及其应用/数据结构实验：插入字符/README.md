# 数据结构实验：插入字符

## 描述

给定一个全部由小写字母组成的字符串。

现在头部插入一个字符并输出结果。

字符串采用顺序表存储，结构如下：

typedef struct

{

    char *data;

    int length;

}SeqList;

你只需要实现以下两个函数：

void CreateSeqList(SeqList &lst, char s[]);//使用字符串s构造一个顺序表并进行初始化

void Insert(SeqList &lst, char c);//将字符c插入到顺序表的开头

部分代码已经给定，提交时请勿包含给定代码。

```cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char *data;
    int length;
}SeqList;
void CreateSeqList(SeqList &lst, char s[]);
void Insert(SeqList &lst, char c);
int main()
{
    SeqList lst;
    char s[101], c;
    gets(s);//输入初始字符串
    CreateSeqList(lst, s);//创建并初始化顺序表
    int n, i;
    scanf("%d", &n);
    while(n--)
    {
        getchar();//吃回车
        c = getchar();//输入字符
        Insert(lst, c);//插入字符到表头
        for(i=0;i<lst.length;i++)//输出
            putchar(lst.data[i]);
        putchar('\n');
    }
    return 0;
}
```

## 输入

第一行为初始字符串，全部由小写字母组成，最长不超过100。

第二行为一个正整数n（n<=100），表示待插入的字母个数。

接下来有若干行，每行为一个待插入的小写字母。

## 输出

每插入一个字符，输出结果序列。

## 样例输入

```
abcd
4
f
e
d
a
```

## 样例输出

```
fabcd
efabcd
defabcd
adefabcd
```