#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int cost;
    int num;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int c, int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->cost = c;
    newNode->num = n;
    newNode->next = NULL;
    return newNode;
}

void Add(Node *head, int m, int x)
{
    Node *p = head;
    while (p->next)
    {
        if (p->next->cost > x)
        {
            Node *q = (Node *)malloc(sizeof(Node));
            q->cost = x;
            q->num = m;
            q->next = p->next;
            p->next = q;
            return;
        }
        else if (p->next->cost == x)
        {
            p->next->num = m + p->next->num;
            return;
        }
        p = p->next;
    }
    Node *q = (Node *)malloc(sizeof(Node));
    q->cost = x;
    q->num = m;
    q->next = p->next;
    p->next = q;
}

void printLinkedList(Node *head)
{
    Node *current = head->next;
    while (current)
    {
        printf("%d %d\n", current->num, current->cost);
        current = current->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *head = createNode(0, 0);
    int i;
    for (i = 0; i < n; ++i)
    {
        int num, cost;
        scanf("%d %d", &num, &cost);
        Add(head, num, cost);
    }
    int m, x;
    scanf("%d %d", &m, &x);
    Add(head, m, x);
    printLinkedList(head);
    return 0;
}
