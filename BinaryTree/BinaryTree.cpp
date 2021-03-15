//
// Created by KeenJackdaw on 2021/2/27.
//
#include "BinaryTree.h"

// 前序递归遍历
void BinaryTreeSolution::PreOrderTraversal(TreeNode *root, vector<int> *vector1) {
	// 因为是前序 所以拿到root就需要把root的值放到vector里 当然要判断root是否为nullptr
	if (root == nullptr) return;

	vector1->push_back(root->val);
	// 接下来就是递归了, 先左边后右边
	PreOrderTraversal(root->left, vector1);
	PreOrderTraversal(root->right, vector1);
}

// 中序递归遍历
void BinaryTreeSolution::MiddleOrderTraversal(TreeNode *root, vector<int> *vector1) {
	if (root == nullptr) return;

	// 先左边再右边，左子树为null，说明到达尽头，需要push back
	MiddleOrderTraversal(root->left, vector1);
	vector1->push_back(root->val);
	MiddleOrderTraversal(root->right, vector1);
}

// 后序递归遍历
void BinaryTreeSolution::PostOrderTraversal(TreeNode *root, vector<int> *vector1) {
	if (root == nullptr) return;

	PostOrderTraversal(root->left, vector1);
	PostOrderTraversal(root->right, vector1);
	vector1->push_back(root->val);
}

// 前序迭代实现
void BinaryTreeSolution::PreOrderLoopTraversal(TreeNode *root, vector<int> *vector1) {
	// 迭代的实现需要栈的帮助，需要一个数组来记录一个节点是否已经被记录到vector里面，一个map来记录是否去过左子树，一个map来记录是否去过右子树
	if (root == nullptr) return;

	std::map<TreeNode*, bool> record;
	std::map<TreeNode*, bool> leftRecord;
	std::map<TreeNode*, bool> rightRecord;

	std::stack stack = std::stack<TreeNode*>();
	stack.push(root); // 首先push根节点

	// 当stack为空时，相当于所有节点都遍历过了
	while (!stack.empty()){
		if (!record[stack.top()]) { // 当record中没有记录
			vector1->push_back(stack.top()->val); // 将val push back 到vector中
			record[stack.top()] = true; // 将record中该节点的记录置为true，代表已经记录过了
		}

		TreeNode *left = stack.top()->left;
		TreeNode *right = stack.top()->right;

		if( left != nullptr && !leftRecord[stack.top()]) { // 如果左子树为null或者已经去过左子树了，则判断下一个条件，否则将leftRecord中的该节点记录置为true，代表已经去过左子树了
			leftRecord[stack.top()] = true;
			stack.push(left);
		}
		else if (right != nullptr && !rightRecord[stack.top()]) { // 同上
			rightRecord[stack.top()] = true;
			stack.push(right);
		}
		else // 如果上面两个条件都不满足，则将stack最上面的节点pop出来
			stack.pop();
	}
}

TreeNode *BinaryTreeSolution::Insert(TreeNode *root, int val) {
	if (root == nullptr)
		root = new TreeNode{nullptr, nullptr, val};
	else
		if (root->val < val)
			root = Insert(root->right, val);
		else
			if (root->val > val)
				root = Insert(root->left, val);
	return root;
}

TreeNode *BinaryTreeSolution::FindMin(TreeNode *root) {
	if (root == nullptr)
		return nullptr;
	else
		if (root->left == nullptr)
			return root;
		else
			return FindMin(root->left);
}

TreeNode *BinaryTreeSolution::FindMax(TreeNode *root) {
	if (root == nullptr)
		return nullptr;
	else
		if (root->right == nullptr)
			return root;
		else
			return FindMax(root->right);
}

TreeNode *BinaryTreeSolution::Delete(TreeNode *root, int val) {
	TreeNode* tmp;
	if (root == nullptr)
		root = nullptr;
	else
		if (root->val < val)
			root = Delete(root->right, val);
		else
			if (root->val > val)
				root = Delete(root->left, val);
			else {
				if (root->left && root->right) {
					tmp = FindMin(root->right);
					root->val = tmp->val;
					root = Delete(root->right, tmp->val);
				} else {
					tmp = root;
					if (root->right == nullptr)
						root = root->left;
					else
						root = root->right;
					free(tmp);
				}
			}
	return root;
}

TreeNode *BinaryTreeSolution::Find(TreeNode *root, int val) {
	if (root == nullptr)
		return nullptr;
	else
		if (root->val < val)
			return Find(root->right, val);
		else
			if (root->val > val)
				return Find(root->left, val);
			else
				return root;
}

