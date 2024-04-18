#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder, int& preorderIndex, int inorderStart, int inorderEnd, unordered_map<char, int>& inorderMap) {
	if (inorderStart > inorderEnd) return NULL;
	
	char rootValue = preorder[preorderIndex++];
	TreeNode* root = new TreeNode(rootValue);
	int inorderIndex = inorderMap[rootValue];
	
	root->left = buildTree(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1, inorderMap);
	root->right = buildTree(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd, inorderMap);
	
	return root;
}

void postorderTraversal(TreeNode* root) {
	if (root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->val;
}

int main() {
	string preorderStr, inorderStr;
	cin >> preorderStr >> inorderStr;
	
	vector<char> preorder(preorderStr.begin(), preorderStr.end());
	vector<char> inorder(inorderStr.begin(), inorderStr.end());
	
	unordered_map<char, int> inorderMap;
	for (int i = 0; i < inorder.size(); i++) {
		inorderMap[inorder[i]] = i;
	}
	
	int preorderIndex = 0;
	TreeNode* root = buildTree(preorder, inorder, preorderIndex, 0, inorder.size() - 1, inorderMap);
	
	postorderTraversal(root);
	cout << endl;
	
	return 0;
}
