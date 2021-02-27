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
	// 前序遍历
	void PreOrderTraversal(TreeNode *root, vector<int> *vector1) {
		// 因为是前序 所以拿到root就需要把root的值放到vector里 当然要判断root是否为nullptr
		if (root == nullptr) return;

		vector1->push_back(root->val);
		// 接下来就是递归了
		// 首先如果root的左子树为null，右子树不为null 则继续遍历右子树, 相反同理
		if (root->left == nullptr && root->right != nullptr) PreOrderTraversal(root->right, vector1);
		if (root->left != nullptr && root->right == nullptr) PreOrderTraversal(root->left, vector1);

		// 如果两个子树都是null 则直接返回
		if (root->left == nullptr && root->right == nullptr) return;
	}
};

