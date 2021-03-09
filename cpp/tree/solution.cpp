#include "solution.h"

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
 * @brief Verify that a binary search tree (BST) is vaild
 * @param[in] root    pointer to the tree root
 * @return Boolean, BST is vaild or not
 */
bool Solution::isValidBST(TreeNode* root)
{
    stack<tuple<TreeNode*, int, int, bool, bool>> frontier;
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
