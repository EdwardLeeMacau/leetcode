#include "bst.h"
#include "gtest/gtest.h"

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
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
