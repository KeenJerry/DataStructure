//
// Created by KeenJackdaw on 2021/2/28.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct TreeNode {
	TreeNode *left;
	TreeNode *right;
	int val;
};

class BinaryTreeSolution {
public:
	// 前序递归遍历
	void PreOrderTraversal(TreeNode *root, vector<int> *vector1);

	// 中序递归遍历
	void MiddleOrderTraversal(TreeNode *root, vector<int> *vector1);

	// 后序递归遍历
	void PostOrderTraversal(TreeNode *root, vector<int> *vector1);

	// 前序迭代实现
	void PreOrderLoopTraversal(TreeNode *root, vector<int> *vector1);
};

#endif //DATASTRUCTURE_BINARYTREE_H
