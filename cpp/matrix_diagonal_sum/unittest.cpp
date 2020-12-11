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

    EXPECT_EQ(sol.diagonalSum(grid0), 2);

    vector<vector<int>> grid1 = {
        {5}
    };

    EXPECT_EQ(sol.diagonalSum(grid1), 5);

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    EXPECT_EQ(sol.diagonalSum(grid2), 25);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}