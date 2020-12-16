#include "binaryTreeNode.h"

inline int max(int a, int b)
{
    return (a > b)? a : b;
}

TreeNode::TreeNode() : 
    val(0), left(nullptr), right(nullptr) 
{

}

TreeNode::TreeNode(int x) : 
    val(x), left(nullptr), right(nullptr) 
{

}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : 
    val(x), left(left), right(right) 
{

}

int TreeNode::height()
{
    if (left && right) {
        return max(left->height(), right->height()) + 1;
    } else if (left) {
        return left->height() + 1;
    } else if (right) {
        return right->height() + 1;
    } else {
        return 0;
    }
}