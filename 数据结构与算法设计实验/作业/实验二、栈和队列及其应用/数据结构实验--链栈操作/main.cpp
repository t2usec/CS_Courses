#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkStack {
	int data;
	struct LinkStack* next;
} LinkStack;

LinkStack* InitStack() {
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->next = NULL;
	return s;
}

LinkStack* Push(LinkStack* s, int x) {
	LinkStack* newS = (LinkStack*)malloc(sizeof(LinkStack));
	newS->data = x;
	newS->next = s;
	return newS;
}

int GetTop(LinkStack* s, int* x) {
	if (s->next == NULL) {
		return 0;
	}
	*x = s->data;
	return 1;
}

LinkStack* Pop(LinkStack* s) {
	if (s->next == NULL) {
		printf("EMPTY\n");
		return s;
	}
	printf("%d\n", s->data);
	return s->next;
}

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
