# 数据结构实验：顺序队列

## 描述

创建一个顺序队列，能够完成队列的初始化、入队、出队、获取队首和队尾元素、销毁队列等操作。 

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
void Destroy(SqQueue* q)
{
	free(q->data);
}

int main()
{
    SqQueue q;
    InitQueue(&q);
    char cmd[10];
    int x, res;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "enq")==0)
        {
            scanf("%d", &x);
            EnQueue(&q, x);
        }
        else if(strcmp(cmd, "front")==0)
        {
            if(Empty(&q))
                printf("EMPTY\n");
            else
                printf("%d\n", Front(&q));
        }
        else if(strcmp(cmd, "back")==0)
        {
            if(Empty(&q))
                printf("EMPTY\n");
            else
                printf("%d\n", Back(&q));
        }
        else
        {
            if(Empty(&q))
                printf("EMPTY\n");
            else
                printf("%d\n", DeQueue(&q));
        }
    }
    Destroy(&q);
    return 0;
}
```

## 输入

输入数据由以下几种命令组成：

（1）enq x：将x入队

（2）deq：出队

（3）front：获取队首元素

（4）back：获取队尾元素

每个命令占一行，以EOF结束。

总的命令个数不会超过500。

## 输出

当执行deq时输出出队的元素，当执行front时输出队首元素，当执行back时输出队尾元素，当队为空时，需要输出EMPTY。

## 样例输入

```
enq 1
enq 2
front
deq
enq 3
front
back
```

## 样例输出

```
1
1
2
3
```