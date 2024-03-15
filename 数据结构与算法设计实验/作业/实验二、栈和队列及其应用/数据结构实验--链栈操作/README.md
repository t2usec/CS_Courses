# 数据结构实验--链栈操作

## 描述

创建一个链栈，能够完成栈的初始化、入栈、出栈、获取栈顶元素、销毁栈等操作。

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
void Destroy(LinkStack *head)
{
    LinkStack *p = head;
    while(p)
    {
        head = head->next;
        free(p);
        p=head;
    }
}

int main()
{
    LinkStack *linkStack;
    linkStack = InitStack();
    char cmd[10];
    int x, res;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "push")==0)
        {
            scanf("%d", &x);
            linkStack = Push(linkStack, x);
        }
        else if(strcmp(cmd, "top")==0)
        {
            res = GetTop(linkStack, &x);
            if(res==0)
                printf("EMPTY\n");
            else
                printf("%d\n", x);
        }
        else
            linkStack = Pop(linkStack);
    }
    Destroy(linkStack);
    return 0;
}
```

## 输入

输入数据由以下几种命令组成：

（1）push x：将x压入栈

（2）pop：出栈

（3）top：获取栈顶元素

每个命令占一行，以EOF结束。

## 输出

当执行pop时输出出栈的元素，当执行top时输出栈顶元素。

当栈为空时，需要输出EMPTY。

## 样例输入

```
push 7
push 3
top
pop
pop
pop
```

## 样例输出

```
3
3
7
EMPTY
```