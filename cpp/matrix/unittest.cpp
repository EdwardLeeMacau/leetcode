#include "gtest/gtest.h"
#include "solution.h"
#include "subrectangle.h"

using namespace std;

class SubrectangleTest: public ::testing::Test {

};

class SolutionTest : public ::testing::Test {

};

TEST_F(SubrectangleTest, test_0)
{
	/**
	 * Your SubrectangleQueries object will be instantiated and called as such:
	 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
	 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
	 * int param_2 = obj->getValue(row,col);
	 */

	SubrectangleQueries* obj;
	vector<vector<int>> grid0 = {
        { 4,  3,  2, -1},
        { 3,  2,  1, -1},
        { 1,  1, -1, -2},
        {-1, -1, -2, -3},
    };

	obj = new SubrectangleQueries(grid0);
    EXPECT_EQ(obj->getValue(0, 0), 4);
	obj->updateSubrectangle(0, 0, 2, 2, 0);
	EXPECT_EQ(obj->getValue(0, 0), 0);
	EXPECT_EQ(obj->getValue(3, 3), -3);
	obj->updateSubrectangle(3, 3, 3, 3, 0);
	EXPECT_EQ(obj->getValue(3, 3), 0);
	delete obj;

    vector<vector<int>> grid1 = {
        { 3,  2},
        { 1,  0}
    };

	obj = new SubrectangleQueries(grid1);
    EXPECT_EQ(obj->getValue(0, 0), 3);
	delete obj;

    vector<vector<int>> grid2 = {
        { 1,  -1},
        { -1, -1}
    };

	obj = new SubrectangleQueries(grid2);
    EXPECT_EQ(obj->getValue(0, 0), 1);
	delete obj;

    vector<vector<int>> grid3 = {
        {-1},
    };

	obj = new SubrectangleQueries(grid3);
    EXPECT_EQ(obj->getValue(0, 0), -1);
	delete obj;
}

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

TEST_F(SolutionTest, test_1)
{
    Solution sol;
    vector<vector<int>> grid = {
        {5}
    };

    EXPECT_EQ(sol.cherryPickup(grid), 5);
}

TEST_F(SolutionTest, test_2)
{
    Solution sol;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    EXPECT_EQ(sol.cherryPickup(grid), 32);
}

TEST_F(SolutionTest, test_3)
{
    Solution sol;
    vector<vector<int>> grid = {
        {4, 3, 2, 0}, 
        {3, 2, 1, 1},
        {1, 1, 1, 2},
        {1, 1, 2, 3},
    };
    
    EXPECT_EQ(sol.cherryPickup(grid), 16);
}

TEST_F(SolutionTest, test_4)
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
