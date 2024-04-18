# 数据结构实验：二叉树A+B

## 描述

给定两棵二叉树，将两棵树相同位置的结点值相加作为新结点，如果某棵树结点为空，则使用非空的结点作为新结点。

例如：

![](https://www.tzcoder.cn/acmhome/judge/images/root-5417.jpg)

后台已经定义了以下类型：

```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

其它代码后台已经全部完成，您只需实现并提交以下函数：

`struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)`

## 输入

输入包括2行，每行描述一棵二叉树，使用若干个整数（不超过512）表示一棵二叉树顺序表示时的结点元素值，其中0表示二叉树对应结点为空。输入以-1结束。

## 输出

输出为二叉树的中序遍历结果，空格隔开。

## 样例输入

```
1 3 2 5 -1
2 1 3 0 4 0 7 -1
```

## 样例输出

```
5 4 4 3 5 7
```