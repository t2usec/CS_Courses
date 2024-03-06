# 数据结构实验：顺序表操作

## 描述

对以顺序存储结构存储的线性表，验证其建表、初始化、插入、删除、索引、查找、就地逆置、销毁等操作。

顺序表定义如下：

```cpp
typedef int Elemtype;

typedef struct
{
    Elemtype *data;
    int length;
}SeqList;
```

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```cpp
//打印
void PrintSeqList(SeqList &L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(i)
            printf(" ");
        printf("%d", L.data[i]);
    }
    printf("\n");
}
//销毁
void DestroySeqList(SeqList &L)
{
    free(L.data);
}

int main()
{
    SeqList L;
    CreateSeqList(L);//建表
    char cmd[20];
    int pos;
    Elemtype x;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "Init")==0)//初始化
            InitSeqList(L);
        else if(strcmp(cmd, "Print")==0)//打印表
            PrintSeqList(L);
        else if(strcmp(cmd, "Insert")==0)//位置前插入元素
        {
            scanf("%d%d", &pos, &x);
            InsertSeqList(L, pos, x);
        }
        else if(strcmp(cmd, "Delete")==0)//删除
        {
            scanf("%d", &pos);
            DeleteSeqList(L, pos);
        }
        else if(strcmp(cmd, "GetElem")==0)//索引
        {
            scanf("%d", &pos);
            GetElemInSeqList(L, pos, x);
            printf("%d\n", x);
        }
        else if(strcmp(cmd, "FindElem")==0)//查找
        {
            scanf("%d", &x);
            pos = FindInSeqList(L, x);
            if(pos == -1)
                printf("Not found\n");
            else
                printf("%d\n", pos);
        }
        else if(strcmp(cmd, "Reverse")==0)//逆置
        {
            ReverseSeqList(L);
        }
        else
            break;
    }
    DestroySeqList(L);//销毁
    return 0;
}
```

## 输入

各个命令以及相关数据，它们对应的格式如下：

（1）初始化：Init n a1, a2, ..., an，表示重新建立一个n个元素的顺序表；

（2）打印表：Print，直接输出当前的顺序表，各个元素值空格隔开；

（3）插入：Insert pos x, 表示将x插入到pos位置前（位置下标0开始），如果pos下标不在顺序表范围，不执行该操作；

（4）删除：Delete pos, 表示删除pos位置的元素（位置下标0开始），如果pos下标不在顺序表范围，不执行该操作；

（5）索引：GetElem pos, 表示获得pos位置的值（位置下标0开始）并输出，pos下标一定有效；

（6）查找：FindElem x, 查找x元素首次出现的位置（位置下标0开始）；

（7）逆置：Reverse，将顺序表各个元素逆置。

（8）退出：Exit

顺序表最大不会超过200个元素。

## 输出

当碰到Print命令时，按要求打印出顺序表。

当碰到GetElem命令时，一行中输出获得的元素值。

当碰到FindElem命令时，如果找不到输出Not found，否则输出pos位置值，占一行。

## 样例输入

```
Init 3 1 2 3
Print
Insert 3 4
Print
Delete 1
Print
GetElem 1
FindElem 5
Reverse
Print
```

## 样例输出

```
1 2 3
1 2 3 4
1 3 4
3
Not found
4 3 1
```