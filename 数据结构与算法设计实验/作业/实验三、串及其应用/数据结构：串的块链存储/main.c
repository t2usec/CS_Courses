Node * CreateString() {
	char str[101];
	gets(str);
	int i,j=0;
	Node *head=NULL,*tail=head,*p;
	for(i=0;str[i]!='\0';i++)
	{
		if(j==0)
		{
			p=(Node*)malloc(sizeof(Node));
			p->next=NULL;
			if(head==NULL)
			{
				head=p;
			}
			else{
				tail->next=p;
			}
			tail=p;
		}
		p->data[j++]=str[i];
		if(j==NodeSize)
		{
			j=0;
		}
	}
		while(j>0&&j<NodeSize)
		{
			p->data[j++]='#';
		}
	return head;
}