#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol = Solution();

    vector<int> test0 = {30, 20, 150, 100, 40};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test0), 3);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
