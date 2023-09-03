#include "solution.h"

#include <queue>

/**
 * @brief Learn how to traverse the binary search tree
 * @score (runtime / memory) (52.84% / 82.90%)
 * @time-complexity O(N), N stands for the number of nodes
 * @space-complexity O(2 ^ D), D stands for the levels of the tree, and 2 ^ D < N
 */
std::vector<double> Solution::averageOfLevel(TreeNode *root)
{
    std::queue<TreeNode *> frontier;
    std::vector<double> ans;
    TreeNode* node;
    int currentCount, count;
    int nextCount = 1;
    int level = 0;

    frontier.push(root);

    /** Traverse by breadth first search (BFS) algorithm. A level for each loop **/
    while (nextCount)
    {
        count = currentCount = nextCount;
        ans.push_back(0);
        nextCount = 0;

        while (count--)
        {
            node = frontier.front();
            frontier.pop();

            ans[level] += node->val / currentCount;

            if (node->left) {
                frontier.push(node->left);
                ++nextCount;
            }

            if (node->right) {
                frontier.push(node->right);
                ++nextCount;
            }
        }

        ++level;
    }

    return ans;
}
