#define MAX_SIZE 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SqQueue {
	int data[MAX_SIZE];
	int front;
	int rear;
} SqQueue;

void InitQueue(SqQueue *q) {
	q->front = 0;
	q->rear = 0;
}

int IsEmpty(SqQueue q) {
	return q.front == q.rear;
}

int IsFull(SqQueue q) {
	return (q.rear + 1) % MAX_SIZE == q.front;
}

int EnQueue(SqQueue *q, int x) {
	if (IsFull(*q)) {
		return 0;
	} else {
		q->data[q->rear] = x;
		q->rear = (q->rear + 1) % MAX_SIZE;
		return 1;
	}
}

int DeQueue(SqQueue *q, int *x) {
	if (IsEmpty(*q)) {
		return 0;
	} else {
		*x = q->data[q->front];
		q->front = (q->front + 1) % MAX_SIZE;
		return 1;
	}
}

int QueueLength(SqQueue q) {
	return (q.rear - q.front + MAX_SIZE) % MAX_SIZE;
}

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
