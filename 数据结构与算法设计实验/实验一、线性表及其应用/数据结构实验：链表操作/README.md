# 数据结构实验：链表操作

## 描述

对以链表存储结构存储的线性表，验证其建表、初始化、插入、删除、查找、更新、就地逆置、销毁等操作。

链表结点Node包含：整型数据data，指向下一个结点的指针next

链表包含一个空的头结点。

后台已经实现链表结点定义，链表创建，链表打印以及主函数，您不需要实现：

C/C++定义


typedef int Elemtype;

typedef struct node

{

    Elemtype  data;

    struct node *next;

}Node;

Python定义：


class Node:

    def __init__(self, data, nxt):

        self.data = data

        self.next = nxt

您需要实现以下函数的定义，请勿包含其它代码。

C/C++：

void Insert(Node* head, int pos, Elemtype x);//在链表的第pos（从1开始）位置前插入值为x的结点，head为头指针

void Delete(Node* head, int pos);//删除链表pos（从1开始）位置的元素，head为头指针

int Find(Node* head, Elemtype x);//查找值为x的第一个结点，找到返回位置（从1开始），否则返回-1

void Update(Node* head,int pos, Elemtype x);//将链表第pos（从1开始）位置的值修改为x

Node* Reverse(Node *head);//将链表所有元素逆置

Python：

Insert(head, pos, x)#在链表的第pos（从1开始）位置前插入值为x的结点，head为头指针

Delete(head, pos)#删除链表pos（从1开始）位置的元素，head为头指针

Find(head, x)#查找值为x的第一个结点，找到返回位置（从1开始），否则返回-1

Update(head, pos, x)#将链表第pos（从1开始）位置的值修改为x

Reverse(head)#将链表所有元素逆置

## 输入

各个命令以及相关数据，它们对应的格式如下：

（1）插入：Insert pos x, 表示将x插入到pos位置前（位置下标1开始）；

（2）删除：Delete pos, 表示删除pos位置的元素（位置下标1开始）；

（3）查找：Find x, 查找x元素首次出现的pos位置的值（位置下标1开始）；

（3）更新：Update pos x, 将pos位置的值替换为x（位置下标1开始）；

（5）逆置：Reverse，将链表各个元素逆置。

（6）退出：Exit

数据保证pos位置有效。

## 输出

当碰到Find命令时，输出找到的元素的pos值，若找不到输出-1；

其它命令均在一行内输出当前链表元素，空格隔开。

## 样例输入

```
5
1 2 3 4 5
Delete 2
Insert 3 6
Find 4
Update 3 7
Reverse
Exit
```

## 样例输出

```
1 3 4 5
1 3 6 4 5
4
1 3 7 4 5
5 4 7 3 1
```