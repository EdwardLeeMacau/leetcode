#include "solution.h"

#include "gtest/gtest.h"

#include "bst.h"

using namespace std;

class SolutionTest : public ::testing::Test 
{
public:
    Solution sol;
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
TEST_F(SolutionTest, test_1)
{
    BST *tree = new BST(new TreeNode(3, new TreeNode(1), new TreeNode(5)));
    EXPECT_EQ(sol.isValidBST(tree->root), true);
    
    delete tree;
}

TEST_F(SolutionTest, test_2)
{
    BST *tree = new BST(new TreeNode(4, new TreeNode(2), new TreeNode(6)));
    EXPECT_EQ(sol.isValidBST(tree->root), true);
    
    delete tree;
}

TEST_F(SolutionTest, test_3)
{
    BST *tree = new BST(new TreeNode(2, new TreeNode(4), new TreeNode(6)));
    EXPECT_EQ(sol.isValidBST(tree->root), false);
    
    delete tree;
}

TEST_F(SolutionTest, test_4)
{
    BST *tree = new BST(new TreeNode(2, new TreeNode(2), new TreeNode(6)));
    EXPECT_EQ(sol.isValidBST(tree->root), false);
    
    delete tree;
}

TEST_F(SolutionTest, test_5)
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

TEST_F(SolutionTest, test_6)
{
    BST *tree = new BST(new TreeNode(2147483647));
    EXPECT_EQ(sol.isValidBST(tree->root), true);

    delete tree;
}

TEST_F(SolutionTest, test_7)
{
    BST *tree = new BST(
        new TreeNode(2147483647,
            new TreeNode(2147483646),
            NULL
        ));
    EXPECT_EQ(sol.isValidBST(tree->root), true);

    delete tree;
}

TEST_F(SolutionTest, test_8)
{
    BST *tree = new BST(
        new TreeNode(2147483647,
            new TreeNode(-2147483648),
            NULL
        ));
    EXPECT_EQ(sol.isValidBST(tree->root), true);

    delete tree;
}

TEST_F(SolutionTest, test_9)
{
	TreeNode *root = new TreeNode(7);
	root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));
	root->left = new TreeNode(3);

	BSTIterator *iter = new BSTIterator(root);
	EXPECT_EQ(iter->next(), 3);
	EXPECT_EQ(iter->hasNext(), true);

	EXPECT_EQ(iter->next(), 7);
	EXPECT_EQ(iter->hasNext(), true);

	EXPECT_EQ(iter->next(), 9);
	EXPECT_EQ(iter->hasNext(), true);

	EXPECT_EQ(iter->next(), 15);
	EXPECT_EQ(iter->hasNext(), true);

	EXPECT_EQ(iter->next(), 20);
	EXPECT_EQ(iter->hasNext(), false);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}