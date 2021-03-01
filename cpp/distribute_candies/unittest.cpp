#include "solution.h"
#include "gtest/gtest.h"

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;
    
    std::vector<int> test0 = {1, 1, 2, 3};
    EXPECT_EQ(sol.distributeCandies(test0), 2);
}

TEST_F(SolutionTest, test_1)
{
    Solution sol;

    std::vector<int> test1 = {1, 1};
    EXPECT_EQ(sol.distributeCandies(test1), 1);
}

TEST_F(SolutionTest, test_2)
{
    Solution sol;

    std::vector<int> test2 = {1, 1, 1, 1, 1, 1};
    EXPECT_EQ(sol.distributeCandies(test2), 1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
