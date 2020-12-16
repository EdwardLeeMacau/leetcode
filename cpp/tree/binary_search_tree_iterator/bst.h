#ifndef BST_H_
#define BST_H_

#include <unistd.h>
#include <stack>

class TreeNode
{
public:
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}

	int val;
	TreeNode *left;
	TreeNode *right;
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root);

	int next();
	bool hasNext();

private:
	std::stack<TreeNode*> frontier;
};

#endif
