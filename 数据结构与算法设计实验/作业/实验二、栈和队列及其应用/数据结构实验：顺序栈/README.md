# 数据结构实验：顺序栈

## 描述

创建一个顺序栈，能够完成栈的初始化、入栈、出栈、获取栈顶元素、销毁栈等操作。 

部分代码已经给出，请补充完整，提交时请勿包含已经给出的代码。

```c
void InitStack(SqStack *s)
{
    s->size = 500;
    s->base = (Elemtype*)malloc(sizeof(Elemtype)*s->size);
    s->top = -1;
}

void Destroy(SqStack *s)
{
	free(s->base);
}

int main()
{
	SqStack s;
	InitStack(&s);
	char cmd[10];
	int x, res;
	while(scanf("%s", cmd)!=EOF)
	{
		if(strcmp(cmd, "push")==0)
		{
			scanf("%d", &x);
			Push(&s, x);
		}
		else if(strcmp(cmd, "top")==0)
		{
			res = GetTop(s, &x);
			if(res==0)
				printf("EMPTY\n");
			else
				printf("%d\n", x);
		}
		else
		{
			res = Pop(&s, &x);
			if(res==0)
				printf("EMPTY\n");
			else
				printf("%d\n", x);
		}
	}
	Destroy(&s);
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

栈空间最大为500，数据保证最大元素个数不会超过500。

## 样例输入

```
push 1
push 2
top
pop
pop
pop
```

## 样例输出

```
2
2
1
EMPTY
```