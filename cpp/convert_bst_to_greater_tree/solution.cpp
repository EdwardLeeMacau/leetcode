#include "solution.h"

#include <stack>

inline void traverseRightBranches(std::stack<TreeNode*>& container, TreeNode* node) {
    do {
        container.push(node);
        node = node->right;
    } while (node);
}

TreeNode* Solution::convertBST(TreeNode* root) 
{
    std::stack<TreeNode*> frontier;
    TreeNode* node = root;
    int count = 0;

    if (node) {
        traverseRightBranches(frontier, node);
    }

    while (!frontier.empty()) {
        node = frontier.top();
        frontier.pop();

        if (node->left) {
            traverseRightBranches(frontier, node->left);
        }

        node->val += count;
        count = node->val;
    }

    return root;
}
