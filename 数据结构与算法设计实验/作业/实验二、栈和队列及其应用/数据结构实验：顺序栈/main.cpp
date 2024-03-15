#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;

typedef struct SqStack {
	int size;
	Elemtype* base;
	int top;
} SqStack;

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

void Push(SqStack* s, int x) {
	(s->top)++;
	(s->base)[s->top] = x;
}

int GetTop(SqStack s, int* x) {
	if (s.top == -1) {
		return 0;
	}
	*x = s.base[s.top];
	return 1;
}

int Pop(SqStack *s, int* x) {
	if (s->top == -1) {
		return 0;
	}
	*x = s->base[s->top];
	s->top = s->top -1;
	return 1;
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
