# 数据结构实验：单链表元素插入

## 描述

实现函数CreateHeader用于创建空链表，实现Insert函数并调用它完成带头节点链表的创建。 

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
void PrintLinkList(Node *head)
{
    int flag = 0;
    Node *p = head->next, *q;
    while(p)
    {
        if(flag)
            printf(" ");
        flag = 1;
        printf("%d", p->data);
        q = p;
        p = p->next;
        free(q);
    }
    free(head);
}

int main()
{
    int n, d;

    Node *head;
    CreateHeader(&head);
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &d);
        Insert(head, d);
    }
    PrintLinkList(head);
    return 0;
}
```

```python
def PrintLinkList(head):
    flag = 0
    p = head.next
    while p!=None:
        if flag!=0:
            print(" ", end='')
        flag = 1
        print(p.data, end='')
        p = p.next
    print()

head = CreateHeader()
n = int(input())
a = list(map(int, input().split()))
for d in a:
    Insert(head, d)
PrintLinkList(head)
```

```cpp
void PrintLinkList(Node *head)
{
    int flag = 0;
    Node *p = head->next, *q;
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
    delete head;
}

int main()
{
    int n, d;

    Node *head;
    CreateHeader(&head);
    cin>>n;
    while(n--)
    {
        cin>>d;
        Insert(head, d);
    }
    PrintLinkList(head);
    return 0;
}
```

## 输入

输入n和n个节点，每个元素都插入到链表的最前面。

## 输出

输出创建好的链表并清空。

## 样例输入

```
3
1 2 3
```

## 样例输出

```
3 2 1
```