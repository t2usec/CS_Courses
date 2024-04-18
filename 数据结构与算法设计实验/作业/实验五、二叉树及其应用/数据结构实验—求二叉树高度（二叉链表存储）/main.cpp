#include <bits/stdc++.h>
using namespace std;

// 定义二叉树的节点结构
class Bitnode {
public:
	int data;
	Bitnode *left, *right;
};

// 层次创建二叉树
Bitnode* CreatBitree_level() {
	int data;
	cin >> data;
	if (data == -1) return nullptr; // 输入-1表示当前子树为空
	Bitnode* root = new Bitnode;
	root->data = data;
	root->left = nullptr;
	root->right = nullptr;
	queue<Bitnode*> q;
	q.push(root);
	
	while (!q.empty()) {
		Bitnode* node = q.front();
		q.pop();
		cin >> data; // 输入左子节点数据
		if (data == -1) {
			break;
		}
		Bitnode* n1 = new Bitnode;
		n1->data = data;
		n1->left = nullptr;
		n1->right = nullptr;
		node->left = n1;
		q.push(node->left);
		cin >> data; // 输入右子节点数据
		if (data == -1) {
			break;
		}
		Bitnode* n2 = new Bitnode;
		n2->data = data;
		n2->left = nullptr;
		n2->right = nullptr;
		node->right = n2;
		q.push(node->right);
	}
	return root;
}

// 计算二叉树的高度
int depth(Bitnode* root) {
	if (root == nullptr) return 0;
	int left_depth = depth(root->left);
	int right_depth = depth(root->right);
	return max(left_depth, right_depth) + 1;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		Bitnode* t = CreatBitree_level();
		cout << depth(t) << endl;
	}
	return 0;
}
