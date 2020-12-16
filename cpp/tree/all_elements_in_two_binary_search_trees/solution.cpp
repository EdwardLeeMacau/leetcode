#include "solution.h"

using namespace std;

vector<int> Solution::getAllElements(TreeNode* root1, TreeNode* root2)
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
