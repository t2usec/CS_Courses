Node* Add(Node* A, Node* B) {
	Node *head=(Node*)malloc(sizeof(Node));
	Node *last=head;
	head->next=NULL;
	A=A->next;
	B=B->next;
	while(A!=0&&B!=0) {
		if(B->exp == A->exp) {
			if(A->coef+B->coef) {
				Node*q = (Node*)malloc(sizeof(Node));
				q->next = NULL;
				q->coef = A->coef+B->coef;
				q->exp = A->exp;
				last->next = q;
				last = q;
				A = A->next;
				B = B->next;
			} else {
				A = A->next;
				B = B->next;
			}
		}
		else if(A->exp > B->exp) {
			Node*q = (Node*)malloc(sizeof(Node));
			q->next = NULL;
			q->coef = B->coef;
			q->exp = B->exp;
			last->next = q;
			last = q;
			B = B->next;
		} else {
			Node*q = (Node*)malloc(sizeof(Node));
			q->next = NULL;
			q->coef = A->coef;
			q->exp = A->exp;
			last->next = q;
			last = q;
			A = A->next;
		}
	}
	if(A == NULL) {
		last->next = B;
		return head;
	}
	last->next = A;
	return head;
}