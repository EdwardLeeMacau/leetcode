#ifndef BINARY_TREE_NODE_H_
#define BINARY_TREE_NODE_H_

/**
 * @brief classic definition of a tree node with at most 2 childs
 */
class TreeNode 
{
public:
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);

    int val;
    TreeNode *left;
    TreeNode *right;
};

#endif /* !BINARY_TREE_NODE_H_ */