#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* CreatBitree_level() {
	int data,front=1,rear=0;
	struct TreeNode *t,*root,*q[1001];
	while(scanf("%d", &data),data!=-1)
	{
		if (data==0)
			t=NULL;
		else {
			t=(struct TreeNode*)malloc(sizeof(struct TreeNode));
			t->val = data;
			t->left = nullptr;
			t->right = nullptr;
		}
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

void inOrder(struct TreeNode* root) {
	if (root == nullptr) return;
	inOrder(root->left);
	printf("%d ", root->val);
	inOrder(root->right);
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	if (t1 == NULL && t2 == NULL) return NULL;
	if (t1 == NULL) {
		t1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		t1->val = 0;
		t1->left = NULL;
		t1->right = NULL;
	}
	if (t2 == NULL) {
		t2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		t2->val = 0;
		t2->left = NULL;
		t2->right = NULL;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = t1->val + t2->val;
	root->left = mergeTrees(t1->left, t2->left);
	root->right = mergeTrees(t1->right, t2->right);
	return root;
}

int main() {
	struct TreeNode* t1 = CreatBitree_level();
	struct TreeNode* t2 = CreatBitree_level();
	t1 = mergeTrees(t1, t2);
	inOrder(t1);
	return 0;
}
