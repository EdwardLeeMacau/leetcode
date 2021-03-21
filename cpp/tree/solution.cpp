#include "solution.h"

#include <queue>
#include <stack>
#include <tuple>

#include "bst.h"

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a; a = b; b = tmp;
    return;
}

/**
 * @brief Return the value sum of the deepest leaves
 * @param[in] root    pointer to the tree root
 * @return sum
 */
int Solution::deepestLeavesSum(TreeNode* root)
{
    int sum = 0;
    return sum;
}

/**
 * @brief Verify that a binary search tree (BST) is vaild
 * @param[in] root    pointer to the tree root
 * @return Boolean, BST is vaild or not
 */
bool Solution::isValidBST(TreeNode* root)
{
    stack<tuple<TreeNode*, int, int, bool, bool> > frontier;
    tuple<TreeNode*, int, int, bool, bool> tmp;
    int val, min, max;

    if (root) {
        frontier.push(make_tuple(root, INT_MIN, INT_MAX, false, false));
    }

    while (!frontier.empty()) {
        tmp = frontier.top();

        root = get<0>(tmp);
        val = get<0>(tmp)->val;
        min = get<1>(tmp);
        max = get<2>(tmp);

        if (get<3>(tmp) && val <= min) { 
            return false;
        }

        if (get<4>(tmp) && val >= max) {
            return false;
        }

        frontier.pop();

        if (root->left) {
            if (root->val <= root->left->val) {
                return false;
            } else {
                frontier.push(make_tuple(root->left, min, root->val, get<3>(tmp), true));
            }
        }

        if (root->right) {
            if (root->val >= root->right->val) {
                return false;
            } else {
                frontier.push(make_tuple(root->right, root->val, max, true, get<4>(tmp)));
            }
        }
    }

    return true;
}

/**
 * @score (runtime / memory) (50.59% / 30.43%)
 * @param[in] root     pointer to the tree root
 * @param[in] val      value to insert
 * @param[in] depth    depth to add
 * @return Pointer to tree root
 */
TreeNode* addOneRow(TreeNode* root, int val, int depth)
{
    std::queue<TreeNode*> frontier;
    TreeNode dummy(0, root, nullptr), *node;
    int count, nextCount = 1;
    
    frontier.push(&dummy);

    /* BFS traverse the tree level by level, stop at (depth - 1) */
    for (; depth > 1; --depth) {
        count = nextCount;
        nextCount = 0;

        for (; count; --count) {
            node = frontier.front();
            frontier.pop();
            
            if (node->left) {
                frontier.push(node->left);
                ++nextCount;
            }

            if (node->right) {
                frontier.push(node->right);
                ++nextCount;
            }
        }
    }
    
    while (!frontier.empty()) {
        node = frontier.front(); frontier.pop();
        node->left = new TreeNode(val, node->left, nullptr);
        node->right = new TreeNode(val, nullptr, node->right);
    }

    return dummy.left;
}

/**
 * @score (runtime / memory) (97.92% / 96.96%)
 */
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
{
    std::stack<TreeNode*> frontier_original, frontier_cloned;
    TreeNode *node;

    frontier_original.push(original);
    frontier_cloned.push(cloned);

    while (original != target) {
        original = frontier_original.top();
        frontier_original.pop();

        cloned = frontier_cloned.top();
        frontier_cloned.pop();

        if (original->right) {
            frontier_original.push(original->right);
            frontier_cloned.push(cloned->right);
        }

        if (original->left) {
            frontier_original.push(original->left);
            frontier_cloned.push(cloned->left);
        }
    }
    
    return cloned;
}

/**
 * @brief Return all elements in a BST in ascending order
 * @param[in] root    pointer to the tree root
 * @return container
 */
std::vector<int> Solution::getAllElements(TreeNode* root1, TreeNode* root2)
{
    vector<int> nums;
    BSTIterator iter1(root1);
    BSTIterator iter2(root2);

    while (iter1.hasNext() && iter2.hasNext()) {
        if (iter1.peak() < iter2.peak()) {
            nums.push_back(iter1.next());
        } else {
            nums.push_back(iter2.next());
        }
    }

    while (iter1.hasNext()) {
        nums.push_back(iter1.next());
    }

    while (iter2.hasNext()) {
        nums.push_back(iter2.next());
    }

    return nums;
}
