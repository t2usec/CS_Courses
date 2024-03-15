#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode {
	int data;
	struct QNode* next;
} QNode;

typedef struct LinkQueue {
	QNode* front;
	QNode* tail;
} LinkQueue;

void EnQueue(LinkQueue &q, int x) {
	QNode* newQ = (QNode*)malloc(sizeof(QNode));
	newQ->data = x;
	newQ->next = NULL;
	if (q.front == q.tail || q.front->next == NULL) {
		q.front->next = newQ;
	}
	q.tail->next = newQ;
	q.tail = newQ;
}

int Empty(LinkQueue &q) {
	if (q.front->next == NULL){
		return 1;
	}
	return 0;
}

int Front(LinkQueue &q) {
	return q.front->next->data;
}

int Back(LinkQueue &q) {
	return q.tail->data;
}

int DeQueue(LinkQueue &q) {
	QNode* s = q.front->next;
	int d = s->data;
	q.front->next = q.front->next->next;
	return d;
}

void InitQueue(LinkQueue &q)
{
	q.front = (QNode*)malloc(sizeof(QNode));
	q.front->next=NULL;
	q.tail = q.front;
}

void Destroy(LinkQueue &q)
{
	QNode *p = q.front, *t;
	while(p)
	{
		t = p;
		p = p->next;
		free(t);
	}
}

int main()
{
	LinkQueue q;
	InitQueue(q);
	char cmd[10];
	int x, res;
	while(scanf("%s", cmd)!=EOF)
	{
		if(strcmp(cmd, "enq")==0)
		{
			scanf("%d", &x);
			EnQueue(q, x);
		}
		else if(strcmp(cmd, "front")==0)
		{
			if(Empty(q))
				printf("EMPTY\n");
			else
				printf("%d\n", Front(q));
		}
		else if(strcmp(cmd, "back")==0)
		{
			if(Empty(q))
				printf("EMPTY\n");
			else
				printf("%d\n", Back(q));
		}
		else
		{
			if(Empty(q))
				printf("EMPTY\n");
			else
				printf("%d\n", DeQueue(q));
		}
	}
	Destroy(q);
	return 0;
}
