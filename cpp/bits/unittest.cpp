#include "solution.h"
#include "gtest/gtest.h"

#include "stdio.h"

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;

    EXPECT_EQ(sol.hammingWeight(3), 2);
    EXPECT_EQ(sol.hammingWeight(-3), 31);
    EXPECT_EQ(sol.hammingWeight(9), 2);
    EXPECT_EQ(sol.hammingWeight(-9), 31);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
