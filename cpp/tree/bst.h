#ifndef BST_H_
#define BST_H_

#include "binaryTreeNode.h"

#include <stack>

class BST 
{
public:
	BST();
	BST(TreeNode *);
	~BST();

	TreeNode *root;
};

class BSTIterator
{
public:
	BSTIterator(TreeNode* root);

    int peak();
	int next();
	bool hasNext();

private:
	std::stack<TreeNode*> frontier;
};

#endif /* !BST_H_ */
