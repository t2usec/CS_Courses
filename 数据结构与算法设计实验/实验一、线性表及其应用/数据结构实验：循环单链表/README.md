# 数据结构实验：循环单链表

## 描述

创建一个循环链表，并从任意一个节点出发，遍历整个链表。 

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
void Destroy(Node* head)
{
    Node *p;
    while(head->next!=head)
    {
        p = head->next;
        head->next = p->next;
        free(p);
    }
    free(head);
}

int main()
{
    int n, x;
    scanf("%d", &n);
    Node *head = CreateLinkList(n);
    while(scanf("%d", &x)!=EOF)
    {
        PrintLinkList(head, x);
    }
    Destroy(head);
    return 0;
}
```

```python
def Destroy(head):
    while head.next != head:
        p = head.next
        head.next = p.next
        del p
    del head

n = int(input())
head = CreateLinkList(n)
while True:
    try:
        x = int(input())
        PrintLinkList(head, x)
    except EOFError:
        break
Destroy(head)
```

## 输入

输入数据第一行为正整数n，第二行为n个整数，为链表节点元素值，所有元素值不相同。接下来若干行，每行为一个整数x，为链表中任意一个元素值，输入到文件结束为止。

## 输出

从元素值为x的节点出发，遍历所有节点并输出，元素值之间用空格隔开。

## 样例输入

```
5
1 2 3 4 5
2
3
5
4
```

## 样例输出

```
2 3 4 5 1
3 4 5 1 2
5 1 2 3 4
4 5 1 2 3
```