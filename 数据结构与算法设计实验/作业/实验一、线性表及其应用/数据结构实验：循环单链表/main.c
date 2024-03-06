// TZOJ 5353

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* CreateLinkList(int n) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	head->next = head;
	Node* tail = head;
	int i;
	for (i = 0; i < n; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		scanf("%d", &newNode->data);
		newNode->next = head;
		if (i==0) {
			head = newNode;
		} else {
			tail->next = newNode;
		}
		tail = newNode;
	}
	return head;
}

void PrintLinkList(Node* head, int x) {
	Node* current = head;
	while (current->data != x) {
		current = current->next;
	}
	
	Node* start = current;
	do {
		printf("%d", current->data);
		current = current->next;
		if (current != start) {
			printf(" ");
		}
	} while (current != start);
	printf("\n");
}