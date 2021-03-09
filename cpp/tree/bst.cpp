#include "bst.h"

#include <stdint.h>
#include <stdexcept>

BST::BST() : root(NULL)
{

}

BST::BST(TreeNode *root) : root(root)
{

}

BST::~BST()
{
    delete root;
}

BSTIterator::BSTIterator(TreeNode* root) 
{
	while (root) {
		frontier.push(root);
		root = root->left;
	}
}

int BSTIterator::peak()
{
    if (frontier.empty()) {
        throw std::bad_exception();
    }
    return frontier.top()->val;
}

int BSTIterator::next()
{
	TreeNode* node;
	int ret = 0;

    if (frontier.empty()) {
        throw std::bad_exception();
    }

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

	return ret;
}

bool BSTIterator::hasNext()
{
	return !frontier.empty();
}
