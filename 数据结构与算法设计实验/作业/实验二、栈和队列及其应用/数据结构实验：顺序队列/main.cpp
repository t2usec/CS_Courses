#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SqQueue {
	int* data;
	int front;
	int back;
} SqQueue;

void InitQueue(SqQueue* q) {
	q->data = (int*)malloc(sizeof(int)*500);
	q->front = -1;
	q->back = -1;
}

void EnQueue(SqQueue* q, int x) {
	if(q->front == -1){
		q->front = 0;
	}
	q->back++;
	q->data[q->back] = x;
}

int Empty(SqQueue* q) {
	if ((q->front > q->back) || (q->front == -1 && q->back == -1)) {
		q->front = -1;
		q->back = -1;
		return 1;
	}
	return 0;
}

int Front(SqQueue* q) {
	return q->data[q->front];
}

int Back(SqQueue* q) {
	return q->data[q->back];
}

int DeQueue(SqQueue* q) {
	int s = q->front;
	q->front++;
	return q->data[s];
}

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
