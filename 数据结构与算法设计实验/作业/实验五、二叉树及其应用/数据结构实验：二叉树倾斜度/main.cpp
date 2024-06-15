#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// 深度优先搜索辅助函数
int dfs(struct TreeNode* root, int* tiltSum) {
	if (root == NULL) return 0;
	int leftSum = dfs(root->left, tiltSum);
	int rightSum = dfs(root->right, tiltSum);
	*tiltSum += abs(leftSum - rightSum);
	return leftSum + rightSum + root->val;
}

// 实现findTilt函数
int findTilt(struct TreeNode* root) {
	int tiltSum = 0;
	dfs(root, &tiltSum);
	return tiltSum;
}

// 创建二叉树的辅助函数
struct TreeNode* createTree(int arr[], int* index) {
	if (arr[*index] == -1 || arr[*index] == 0) {
		(*index)++;
		return NULL;
	}
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->val = arr[*index];
	(*index)++;
	newNode->left = createTree(arr, index);
	newNode->right = createTree(arr, index);
	return newNode;
}

int main() {
	int n, index = 0;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	struct TreeNode* root = createTree(arr, &index);
	printf("%d\n", findTilt(root));
	return 0;
}
