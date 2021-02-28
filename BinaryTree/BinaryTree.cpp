//
// Created by KeenJackdaw on 2021/2/27.
//
#include <vector>
using namespace std;

struct TreeNode {
	TreeNode *left;
	TreeNode *right;
	int val;
};

class Solution {
public:
	// 前序递归遍历
	void PreOrderTraversal(TreeNode *root, vector<int> *vector1) {
		// 因为是前序 所以拿到root就需要把root的值放到vector里 当然要判断root是否为nullptr
		if (root == nullptr) return;

		vector1->push_back(root->val);
		// 接下来就是递归了, 先左边后右边
		PreOrderTraversal(root->left, vector1);
		PreOrderTraversal(root->right, vector1);
	}

	// 中序递归遍历
	void MiddleOrderTraversal(TreeNode *root, vector<int> *vector1) {
		if (root == nullptr) return;

		// 先左边再右边，左子树为null，说明到达尽头，需要push back
		MiddleOrderTraversal(root->left, vector1);
		vector1->push_back(root->val);
		MiddleOrderTraversal(root->right, vector1);
	}

	// 后序递归遍历
	void PostOrderTraversal(TreeNode *root, vector<int> *vector1) {
		if (root == nullptr) return;

		PostOrderTraversal(root->left, vector1);
		PostOrderTraversal(root->right, vector1);
		vector1->push_back(root->val);
	}

	//
};

