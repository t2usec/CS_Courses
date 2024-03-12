# 数据结构实验：删除链表元素

## 描述

完成链表的创建、元素查找和删除等操作。

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```cpp
void PrintLinkList(Node *head)
{
    int flag = 0;
    Node *p = head->next, *q;
    while(p)
    {
        if(flag)
            printf(" ");
        flag = 1;
        cout<<p->data;
        q = p;
        p = p->next;
        delete q;
    }
    delete head;
}

int main()
{
    int n, x;
    cin>>n;
    Node *head = CreateLinkList(n);
    cin>>x;
    Node *p = Find(head, x);
    Delete(p);
    PrintLinkList(head);
    return 0;
}
```

## 输入

输入数据第一行为n，表示链表元素个数，第二行为n个整数，表示节点元素值（所有元素值不相等）。

第三行为删除的元素值，一定存在于链表中。

## 输出

输出删除后的链表元素，每个元素值之间用一个空格隔开。

## 样例输入

```
5
1 2 3 4 5
3
```

## 样例输出

```
1 2 4 5
```