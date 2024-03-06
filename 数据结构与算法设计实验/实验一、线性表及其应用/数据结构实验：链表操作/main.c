// TZOJ 5661

#include<stdio.h>
#include<string.h>
void Insert(Node* head, int pos, Elemtype x)
{
 Node *p=head;
 while(--pos)
 {
 p=p->next;
 if(p==NULL)
 return; 
 }
 Node *q=(Node*)malloc(sizeof(Node));
 q->data=x;
 q->next=p->next;
 p->next=q; 
}

void Delete(Node* head, int pos)
{
 Node *p=head;
 while(--pos)
 {
 p=p->next;
 if(p==NULL)
 return; 
 }
 Node *q=p->next;
 p->next=q->next;
 free(q);
}

int Find(Node* head, Elemtype x)
{
 Node *p=head;
 int pos =1;
 while(p->next)
 {
 p=p->next;
 if(p->data==x)
  return pos;
  pos++; 
 }
 return -1;
}

void Update(Node* head,int pos, Elemtype x)
{
 Node *p=head;
 int i;
 for(i=0;i<pos;i++)
 {
 p=p->next;
 if(p==NULL)
 return; 
 } 
 p->data=x;
}

Node* Reverse(Node *head)
{
 Node *p=head->next;
 if(p==NULL||p->next==NULL)
 return head;
 head->next=NULL;
 while(p!=NULL)
 {
  Node *t=p->next;
  p->next=head->next;
  head->next=p;
  p=t; 
 }
 return head;
}