//
// Created by KeenJackdaw on 2021/2/28.
//

#ifndef DATASTRUCTURE_UTILS_H
#define DATASTRUCTURE_UTILS_H
#include "BinaryTree/BinaryTree.h"

class utils {
public:
	static TreeNode *buildTree() {
		auto *node1 = new TreeNode{nullptr, nullptr, 1};
		auto *node2 = new TreeNode{nullptr, nullptr, 2};
		auto *node3 = new TreeNode{nullptr, nullptr, 3};
		auto *node4 = new TreeNode{nullptr, nullptr, 4};
		auto *node5 = new TreeNode{nullptr, nullptr, 5};
		auto *node6 = new TreeNode{nullptr, nullptr, 6};
		auto *node7 = new TreeNode{nullptr, nullptr, 7};

		node1->left = node2;
		node1->right = node3;
		node2->left = node4;
		node2->right = node5;
		node3->left = node6;
		node3->right = node7;

		return node1;
	}

};


#endif //DATASTRUCTURE_UTILS_H
