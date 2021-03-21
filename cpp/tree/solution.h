#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "binaryTreeNode.h"

#include <vector>

class Solution
{
public:
    int deepestLeavesSum(TreeNode* root);
    bool isValidBST(TreeNode* root);
    TreeNode* addOneRow(TreeNode* root, int val, int depth);
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target);
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2);
};

#endif /* !SOLUTION_H_ */