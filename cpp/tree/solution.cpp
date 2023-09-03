#include "solution.h"

#include <queue>
#include <stack>
#include <tuple>

#include "bst.h"

void swap(int& a, int& b)
{
    int tmp = a; a = b; b = tmp;
    return;
}

/**
 * @brief Naive solution: BFS with depth counter
 * @score (runtime / memory) (66.71% / 11.45%)
 */
int Solution::maxDepth(TreeNode* root)
{
    std::stack<std::tuple<TreeNode*, int> > frontier;
    std::tuple<TreeNode*, int> node;
    int depth, maxdepth = 0, count = 0, next_count = 1;

    if (!root) {
        return 0;
    }

    frontier.push(std::make_tuple(root, 1));
    while (!frontier.empty()) {
        count = next_count; next_count = 0;
        node = frontier.top(); frontier.pop();

        root = std::get<0>(node);
        depth = std::get<1>(node);

        if (maxdepth < depth) {
            maxdepth = depth;
        }

        if (root->right) {
            frontier.push(std::make_tuple(root->right, depth + 1));
        }

        if (root->left) {
            frontier.push(std::make_tuple(root->left, depth + 1));
        }
    }

    return maxdepth;
}

/**
 * @score (runtime / memory) (100.00% / 51.85%)
 */
int Solution::sumNumbers(TreeNode* root)
{
    std::stack<std::tuple<TreeNode*, int>> frontier;
    std::tuple<TreeNode*, int> node;
    std::vector<int> ans;
    std::vector<int>::iterator iter, end;
    int buf;

    frontier.push(std::make_tuple(root, 0));
    while (!frontier.empty()) {
        node = frontier.top();
        frontier.pop();

        root = std::get<0>(node);
        buf = std::get<1>(node) * 10 + root->val;

        if (!root->left && !root->right) {
            ans.push_back(buf);
            continue;
        }

        if (root->left) {
            frontier.push(std::make_tuple(root->left, buf));
        }

        if (root->right) {
            frontier.push(std::make_tuple(root->right, buf));
        }
    }

    buf = 0;
    for (iter = ans.begin(), end = ans.end(); iter != end; ++iter) {
        buf += *iter;
    }

    return buf;
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
    std::stack<std::tuple<TreeNode*, int, int, bool, bool> > frontier;
    std::tuple<TreeNode*, int, int, bool, bool> tmp;
    int val, min, max;

    if (root) {
        frontier.push(std::make_tuple(root, INT_MIN, INT_MAX, false, false));
    }

    while (!frontier.empty()) {
        tmp = frontier.top();

        root = std::get<0>(tmp);
        val = std::get<0>(tmp)->val;
        min = std::get<1>(tmp);
        max = std::get<2>(tmp);

        if (std::get<3>(tmp) && val <= min) {
            return false;
        }

        if (std::get<4>(tmp) && val >= max) {
            return false;
        }

        frontier.pop();

        if (root->left) {
            if (root->val <= root->left->val) {
                return false;
            } else {
                frontier.push(std::make_tuple(root->left, min, root->val, std::get<3>(tmp), true));
            }
        }

        if (root->right) {
            if (root->val >= root->right->val) {
                return false;
            } else {
                frontier.push(std::make_tuple(root->right, root->val, max, true, std::get<4>(tmp)));
            }
        }
    }

    return true;
}

/**
 * @score (runtime / memory) (100.00% / 5.49%)
 */
bool Solution::isSymmetric(TreeNode* root)
{
    std::stack<TreeNode*> left, right;
    TreeNode *l, *r;

    left.push(root->left);
    right.push(root->right);

    while (!left.empty()) {
        l = left.top(); r = right.top();

        // Move forward
        left.pop(); right.pop();

        // Check symmetric
        if ((l && !r) || (!l && r)) {
            return false;
        }

        if (!l && !r) {
            continue;
        }

        if (l->val != r->val) {
            return false;
        }

        // Traversal
        left.push(l->right); right.push(r->left);
        left.push(l->left); right.push(r->right);
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
    std::vector<int> nums;
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

/**
 * @score (runtime / memory) (100.00% / 82.45%)
 * @time-complexity  O(N), N is for number of nodes
 * @space-complexity O(N + H), N is for number of nodes, H is the height of the tree
 */
std::vector<int> Solution::inorderTraversal(TreeNode* root)
{
    std::stack<TreeNode*> frontier;
    std::vector<int> ans;

    if (!root) {
        return ans;
    }

    // Always push left node on the top of the middle node
    frontier.push(root);
    while ((root = root->left)) {
        frontier.push(root);
    }

    while (!frontier.empty()) {
        root = frontier.top(); frontier.pop();

        ans.push_back(root->val);

        if ((root = root->right)) {
            // Always push left node on the top of the middle node
            frontier.push(root);
            while ((root = root->left)) {
                frontier.push(root);
            }
        }
    }

    return ans;
}

/**
 * @brief traverse the node with order: middle -> left -> right
 * @score (runtime / memory) (47.19% / 92.43%)
 */
std::vector<int> Solution::preorderTraversal(TreeNode* root)
{
    std::stack<TreeNode*> frontier;
    std::vector<int> ans;

    if (!root) {
        return ans;
    }

    frontier.push(root);
    while (!frontier.empty()) {
        root = frontier.top(); frontier.pop();
        ans.push_back(root->val);

        if (root->right) {
            frontier.push(root->right);
        }

        if (root->left) {
            frontier.push(root->left);
        }
    }

    return ans;
}

/**
 * @brief traverse the node with order: left -> right -> middle
 * @score (runtime / memory) (47.19% / 92.43%)
 */
std::vector<int> Solution::postorderTraversal(TreeNode* root)
{
    std::vector<int> ans;

    return ans;
}

/**
 * @score (runtime / memory) (36.60% / 81.41%)
 */
std::vector<std::vector<int> > Solution::levelOrder(TreeNode* root)
{
    std::queue<TreeNode*> frontier;
    std::vector<std::vector<int> > ans;
    std::vector<int> buf;
    int count = 0, next_count = 1;

    if (!root) {
        return ans;
    }

    frontier.push(root);
    while (!frontier.empty()) {
        count = next_count; next_count = 0;
        buf.clear();
        for (; count; --count) {
            root = frontier.front(); frontier.pop();
            buf.push_back(root->val);

            if (root->left) {
                frontier.push(root->left);
                ++next_count;
            }
            if (root->right) {
                frontier.push(root->right);
                ++next_count;
            }
        }
        ans.push_back(buf);
    }

    return ans;
}

/**
 * @score (runtime / memory) (82.98% / 82.98%)
 */
std::vector<std::vector<int > > Solution::levelOrderBottom(TreeNode* root)
{
    std::vector<std::vector<int> > ans = levelOrder(root);
    std::reverse(ans.begin(), ans.end());

    return ans;
}