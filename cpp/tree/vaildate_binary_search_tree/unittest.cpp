#include "solution.h"
#include "bst.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {
public:
    Solution sol;
};

TEST_F(SolutionTest, test_0)
{
    BST *tree = new BST(new TreeNode(3, new TreeNode(1), new TreeNode(5)));
    EXPECT_EQ(sol.isValidBST(tree->root), true);
    
    delete tree;
}

TEST_F(SolutionTest, test_1)
{
    BST *tree = new BST(new TreeNode(4, new TreeNode(2), new TreeNode(6)));
    EXPECT_EQ(sol.isValidBST(tree->root), true);
    
    delete tree;
}

TEST_F(SolutionTest, test_2)
{
    BST *tree = new BST(new TreeNode(2, new TreeNode(4), new TreeNode(6)));
    EXPECT_EQ(sol.isValidBST(tree->root), false);
    
    delete tree;
}

TEST_F(SolutionTest, test_3)
{
    BST *tree = new BST(new TreeNode(2, new TreeNode(2), new TreeNode(6)));
    EXPECT_EQ(sol.isValidBST(tree->root), false);
    
    delete tree;
}

TEST_F(SolutionTest, test_4)
{
    BST *tree = new BST(
        new TreeNode(5, 
            new TreeNode(4), 
            new TreeNode(6, 
                new TreeNode(3), 
                new TreeNode(7)
        )));
    EXPECT_EQ(sol.isValidBST(tree->root), false);
    
    delete tree;
}

TEST_F(SolutionTest, test_5)
{
    BST *tree = new BST(new TreeNode(2147483647));
    EXPECT_EQ(sol.isValidBST(tree->root), true);

    delete tree;
}

TEST_F(SolutionTest, test_6)
{
    BST *tree = new BST(
        new TreeNode(2147483647,
            new TreeNode(2147483646),
            NULL
        ));
    EXPECT_EQ(sol.isValidBST(tree->root), true);

    delete tree;
}

TEST_F(SolutionTest, test_7)
{
    BST *tree = new BST(
        new TreeNode(2147483647,
            new TreeNode(-2147483648),
            NULL
        ));
    EXPECT_EQ(sol.isValidBST(tree->root), true);

    delete tree;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}