#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 定义二叉树节点结构
typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* insert(Node* node, int data) {
	if (node == NULL) return newNode(data);
	
	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	
	return node;
}

Node* CreateTree(int n) {
	Node* root = NULL;
	int data;
	int i;
	for (i = 0; i < n; ++i) {
		scanf("%d", &data);
		root = insert(root, data);
	}
	return root;
}

void inorderTraversal(Node* root) {
	if (root == nullptr) return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

int main() {
	int n;
	while (cin >> n) {
		Node* root = CreateTree(n);
		inorderTraversal(root);
		cout << endl;
	}
	return 0;
}
