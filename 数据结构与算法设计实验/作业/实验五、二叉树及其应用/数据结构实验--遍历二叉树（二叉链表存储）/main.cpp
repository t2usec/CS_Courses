#include <iostream>
#include <queue>
using namespace std;

struct Bitnode {
	int value;
	Bitnode *left, *right;
};

Bitnode*CreatBitree_level() {
	int data,front=1,rear=0;
	Bitnode*t,*root,*q[1001];
	while(scanf("%d",&data),data!=-1)
	{
		if (data==0)
			t=NULL;
		else
			t=new Bitnode{data, nullptr, nullptr};
		q[++rear]=t;
		if(rear==1) {
			root=t;
		} else {
			if(q[front]!=NULL) {
				if (rear%2==0) {
					q[front]->left=t;
				}
				else
					q[front]->right=t;
			}
			if(rear%2==1)
				front++;
		}
	}
	return root;
}

void postorder(Bitnode *t) {
	if (t == nullptr) return;
	postorder(t->left);
	postorder(t->right);
	cout << " " << t->value;
}

void preorder(Bitnode *t) {
	if (t == nullptr) return;
	cout << " " << t->value;
	preorder(t->left);
	preorder(t->right);
}

void inorder(Bitnode *t) {
	if (t == nullptr) return;
	inorder(t->left);
	cout << " " << t->value;
	inorder(t->right);
}

int main()
{
	Bitnode *t;
	int n;
	cin>>n;
	while(n--)
	{
		t=CreatBitree_level();
		preorder(t);
		cout<<endl;
	}
	return 0;
}