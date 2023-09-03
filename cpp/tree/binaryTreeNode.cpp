#include "binaryTreeNode.h"

#include <unistd.h>

inline int max(int a, int b)
{
    return (a > b)? a : b;
}

TreeNode::TreeNode(): val(0), left(NULL), right(NULL)
{

}

TreeNode::TreeNode(int x): val(x), left(NULL), right(NULL)
{

}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right)
{

}
