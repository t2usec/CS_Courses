#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int value;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* CreatBitree_level() {
	int data,front=1,rear=0;
	TreeNode*t,*root,*q[1001];
	while(cin>>data,data!=-1)
	{
		if (data==0)
			t=NULL;
		else {
			t=new TreeNode;
			t->value = data;
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

// 先序遍历
void preOrder(TreeNode* root) {
	if (root != nullptr) {
		cout << " " << root->value;
		preOrder(root->left);
		preOrder(root->right);
	}
}

// 中序遍历
void inOrder(TreeNode* root) {
	if (root != nullptr) {
		inOrder(root->left);
		cout << " " << root->value;
		inOrder(root->right);
	}
}

// 后序遍历
void postOrder(TreeNode* root) {
	if (root != nullptr) {
		postOrder(root->left);
		postOrder(root->right);
		cout << " " << root->value;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode* root = CreatBitree_level();
		preOrder(root);
		cout<<endl;
		inOrder(root);
		cout<<endl;
		postOrder(root);
		cout<<endl;
	}
	return 0;
}
