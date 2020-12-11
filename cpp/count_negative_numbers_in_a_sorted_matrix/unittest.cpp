#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;

    vector<vector<int>> grid0 = {
        { 4,  3,  2, -1}, 
        { 3,  2,  1, -1},
        { 1,  1, -1, -2},
        {-1, -1, -2, -3},
    };

    EXPECT_EQ(sol.countNegatives(grid0), 8);

    vector<vector<int>> grid1 = {
        { 3,  2},
        { 1,  0}
    };

    EXPECT_EQ(sol.countNegatives(grid1), 0);

    vector<vector<int>> grid2 = {
        { 1,  -1},
        { -1, -1}
    };

    EXPECT_EQ(sol.countNegatives(grid2), 3);

    vector<vector<int>> grid3 = {
        {-1},
    };

    EXPECT_EQ(sol.countNegatives(grid3), 1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}