#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "binaryTreeNode.h"

#include <vector>

class Solution
{
public:
    int maxDepth(TreeNode* root);
    int sumNumbers(TreeNode* root);
    int deepestLeavesSum(TreeNode* root);
    bool isValidBST(TreeNode* root);
    bool isSymmetric(TreeNode* root);
    TreeNode* addOneRow(TreeNode* root, int val, int depth);
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target);
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2);
    std::vector<int> inorderTraversal(TreeNode* root);
    std::vector<int> preorderTraversal(TreeNode* root);
    std::vector<int> postorderTraversal(TreeNode* root);
    std::vector<std::vector<int> > levelOrder(TreeNode* root);
    std::vector<std::vector<int> > levelOrderBottom(TreeNode* root);
};

#endif /* !SOLUTION_H_ */