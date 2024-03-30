# 数据结构实验：简单串模式匹配

## 描述

给定字符串s和t，判断t在s中是否存在，如果存在，返回首次出现的位置（即首次出现的子串首字符的位置，从0开始计算）。

其中s称为主串，t称为模式串。

部分代码已经完成，您只需完成strstr函数的编写，请勿包含给定代码。

int strstr(char* s, char* t);//s为主串，t为模式串

```c
#include <stdio.h>
int strstr(char* s, char* t);
int main()
{
    char s[101], t[101];
    scanf("%s%s", s, t);
    printf("%d\n",strstr(s, t));
    return 0;
}
```

## 输入

第一行为字符串s；

第二行为字符串t。

s和t均不含空格。字符串长度均不超过100。

## 输出

如果存在输出首次出现的位置（从0开始）。

否则输出-1。

## 样例输入

```
ababc
abc
```

## 样例输出

```
2
```