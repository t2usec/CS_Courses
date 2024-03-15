# 数据结构实验--循环队列

## 描述

创建一个循环队列，队列最大元素个数为4。能够实现队列的初始化、入队列、出队列、求队列长度等操作。

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
int main()
{
    SqQueue q;
    char ss[10]; 
    int x, sta,l; 
    InitQueue(&q); 
    while(scanf("%s", ss)!=EOF) 
    {
        if(strcmp(ss, "enter")==0)
        {
            scanf("%d", &x);
            sta= EnQueue(&q,x);
            if(sta==0)
                printf("FULL\n"); 
        }
        else if(strcmp(ss, "length")==0)
        {
            l=QueueLength(q); 
            printf("%d\n", l);
        }
        else
        {
            sta = DeQueue(&q,&x);
            if(sta==0)
                printf("EMPTY\n"); 
            else
                printf("%d\n", x);
        } 
    }
    return 0;
}
```

## 输入

输入数据由以下几种命令组成：

（1）enter x：x入队列

（2）del：出队列

（3）length：求队列长度

每个命令占一行，以EOF结束。

## 输出

当执行enter操作时元素入队，若队满输出FULL。

当执行del时输出出队的元素，若队为空，输出EMPTY。

当执行length时，输出队列长度。

## 样例输入

```
enter 3
enter 15
length
del
del
del
```

## 样例输出

```
2
3
15
EMPTY
```