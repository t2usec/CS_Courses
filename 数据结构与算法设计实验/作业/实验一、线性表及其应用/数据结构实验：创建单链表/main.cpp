// TZOJ 5338

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *CreateLinkList(int n)
{
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // 创建新节点
        Node *p = new Node;
        p->data = x;
        p->next = NULL;
        // 将新节点插入到链表尾部
        if (tail == NULL) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}