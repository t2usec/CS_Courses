# 数据结构：串的块链存储

## 描述

输入一个字符串，请将其用块链结构存储，所谓块链结构是将串分割成多个块，以链表形式存储，链表的每个结点存储一个固定大小的子串。本题假设块的大小为3，块的定义如下：

```
#define NodeSize 3

typedef struct Node
{
    char data[NodeSize];
    struct Node * next;//指向下一块
}Node;
```

如果某一块未能存满字符，用'#'字符代替。

后台已经编写了其他所有代码，您只需实现CreateString函数，用于输入并创建块链结构。

Node * CreateString();//输入字符串，并返回头指针，不含头结点

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NodeSize 3
typedef struct Node
{
    char data[NodeSize];
    struct Node * next;
}Node;

Node * CreateString();
void PrintString(Node* head)
{
    int i, flag = 0;
    Node* temp = head;
    while (temp)
    {
        if(flag)
            printf("->");
        flag = 1;
        for (i = 0; i < NodeSize; i++)
        {
            printf("%c", temp->data[i]);
        }
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node * head = NULL;
    head = CreateString();
    PrintString(head);
    return 0;
}
```

## 输入

输入为一行任意字符组成的字符串，长度为n（0<=n<=100)。

## 输出

输出各个块的内容，中间用“->”隔开。

## 样例输入

```
www.tzcoder.cn
```

## 样例输出

```
www->.tz->cod->er.->cn#
```