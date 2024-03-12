#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *CreateLinkList(int n)
{
    Node *head = new Node;
    Node *last = head;
    head->next = NULL;
    last->next = NULL;
    while (n--)
    {
        Node *q = new Node;
        cin >> q->data;
        q->next = NULL;
        last->next = q;
        last = q;
    }
    return head;
}

Node *Find(Node *head, int x)
{
    while (head->next)
    {
        if (head->next->data == x)
            break;
        head = head->next;
    }
    return head;
}

void Delete(Node *p)
{
    Node *q = p->next;
    p->next = p->next->next;
    delete q;
}

void PrintLinkList(Node *head)
{
    int flag = 0;
    Node *p = head->next, *q;
    while (p)
    {
        if (flag)
            printf(" ");
        flag = 1;
        cout << p->data;
        q = p;
        p = p->next;
        delete q;
    }
    delete head;
}

int main()
{
    int n, x;
    cin >> n;
    Node *head = CreateLinkList(n);
    cin >> x;
    Node *p = Find(head, x);
    Delete(p);
    PrintLinkList(head);
    return 0;
}