# 数据结构：图的邻接表

## 描述

给定一个n个顶点（1到n编号）的有向图，以及若干条边，请对其构造邻接表。

图的基本结构定义如下：

邻接表中的边表结点ArcNode包含：vertex（顶点下标）和next指针（指向下一个邻接点）

图结构Graph包含：vNum（顶点数）、eNum（边数）和head指针数组（邻接表边表头指针）

部分代码已经完成，请补充完整，提交时请勿包含以下给定代码。

```cpp
void PrintGraph(Graph& g)
{
    int i;
    for(i=1; i<=g.vNum; i++)
    {
        ArcNode *p = g.head[i];
        printf("%d", i);
        while(p)
        {
            printf("->%d", p->vertex);
            p = p->next;
        }
        printf("\n");
    }
}
int main()
{
    Graph g;
    CreateGraph(g);
    PrintGraph(g);
    return 0;
}
```

## 输入

第一行为两个正整数n和m，n表示顶点数（顶点从1到n编号），m表示边数。

接下来有m行，每行两个有正整数a和b (a和b不相等，1<=a,b<=n)，表示顶点a到b有一条有向边。

2<=n<=20, 0<=m<=n*(n-1)。

所有边没有重复。

## 输出

输出有n行，每行表示从顶点i(1<=i<=n)出发的邻接点，要求各个邻接点编号从小到大顺序排序。

## 样例输入

```
3 3
1 3
2 3
1 2
```

## 样例输出

```
1->2->3
2->3
3
```