#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;

    BST *tree0a = new BST(new TreeNode(3, new TreeNode(1), new TreeNode(5)));
    BST *tree1a = new BST(new TreeNode(4, new TreeNode(2), new TreeNode(6)));
    vector<int> ans0 = {1, 2, 3, 4, 5, 6};
    vector<int> ret0 = sol.getAllElements(tree0a->root, tree1a->root);
    EXPECT_EQ(ret0.size(), ans0.size());
    if (ret0.size() == ans0.size()) {
        for (int i = 0; i < ret0.size(); ++i) {
            EXPECT_EQ(ret0[i], ans0[i]);
        }
    }
    delete tree0a;
    delete tree1a;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}