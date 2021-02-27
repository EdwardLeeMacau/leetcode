#ifndef BINARY_TREE_NODE_H_
#define BINARY_TREE_NODE_H_

class TreeNode 
{
public:
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);

    int height();

    int val;
    TreeNode *left;
    TreeNode *right;
};

#endif /* !BINARY_TREE_NODE_H_ */