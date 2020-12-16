#include "solution.h"

#include <stack>
#include <tuple>
#include <limits.h>

using namespace std;

void swap(int& a, int& b)
{
    int tmp = a; a = b; b = tmp;
    return;
}

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
