#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "binaryTreeNode.h"

#include <vector>

class Solution
{
public:
    bool isValidBST(TreeNode* root);
    int deepestLeavesSum(TreeNode* root);
    TreeNode* addOneRow(TreeNode* root, int val, int depth);
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2);
};

#endif /* !SOLUTION_H_ */