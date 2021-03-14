#include "solution.h"
#include "gtest/gtest.h"

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;
    std::vector<int> pushed({1, 2, 3, 4, 5});
    std::vector<int> popped({4, 5, 3, 2, 1});

    EXPECT_TRUE(sol.validateStackSequences(pushed, popped));
}

TEST_F(SolutionTest, test_1)
{
    Solution sol;
    std::vector<int> pushed({1, 2, 3, 4, 5});
    std::vector<int> popped({4, 3, 5, 1, 2});

    EXPECT_FALSE(sol.validateStackSequences(pushed, popped));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
