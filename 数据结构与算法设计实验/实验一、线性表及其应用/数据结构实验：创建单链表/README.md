# 数据结构实验：创建单链表

## 描述

根据输入的值创建一个不带头结点的单链表。

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```cpp
void PrintLinkList(Node *head)
{
    int flag = 0;
    Node *p = head, *q;
    while(p)
    {
        if(flag)
            cout<<" ";
        flag = 1;
        cout<<p->data;
        q = p;
        p = p->next;
        delete q;
    }
}

int main()
{
    int n;
    cin>>n;
    Node *h = CreateLinkList(n);
    PrintLinkList(h);
    return 0;
}
```

## 输入

输入n和n个节点元素值。

## 输出

输出节点值并清空链表。

## 样例输入

```
3
1 2 3
```

## 样例输出

```
1 2 3
```