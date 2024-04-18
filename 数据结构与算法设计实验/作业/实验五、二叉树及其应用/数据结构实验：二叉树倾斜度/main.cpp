#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct {
	int sum;
	int tilt;
} SumAndTilt;

SumAndTilt findTiltAndSum(struct TreeNode* node) {
	if (node == NULL) {
		return (SumAndTilt){0, 0};
	}
	
	SumAndTilt left = findTiltAndSum(node->left);
	SumAndTilt right = findTiltAndSum(node->right);
	
	int current_tilt = abs(left.sum - right.sum);
	int total_sum = left.sum + right.sum + node->val;
	
	return (SumAndTilt){total_sum, current_tilt + left.tilt + right.tilt};
}

int findTilt(struct TreeNode* root) {
	SumAndTilt result = findTiltAndSum(root);
	return result.tilt;
}

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

int main() {
	struct TreeNode* root = CreatBitree_level();
	printf("%d\n", findTilt(root));
	return 0;
}
