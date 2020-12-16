#include "bst.h"

#include <iostream>

using namespace std;

BSTIterator::BSTIterator(TreeNode* root) 
{
	while (root) {
		frontier.push(root);
		root = root->left;
	}
}

int BSTIterator::next()
{
	TreeNode* node;
	int ret = 0;

	if (frontier.size()) {
		node = frontier.top();
		ret = node->val;
		frontier.pop();

		if (node->right) {
			node = node->right;
			frontier.push(node);

			while (node->left) {
				node = node->left;
				frontier.push(node);
			}
		}
	}

	return ret;
}

bool BSTIterator::hasNext()
{
	return !frontier.empty();
}
