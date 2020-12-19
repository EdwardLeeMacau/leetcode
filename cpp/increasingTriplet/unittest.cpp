#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {
public:
    Solution sol;
};

TEST_F(SolutionTest, test_0)
{
    vector<int> test = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_1)
{
    vector<int> test = {5, 4, 3, 2, 1};
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_2)
{
    vector<int> test = {2, 1, 5, 0, 4, 6};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_3)
{
    vector<int> test = {2, 2, 3, 0, 2, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_4)
{
    vector<int> test = {1, 2};
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_5)
{
    vector<int> test = {2, 2, 3, 0, 2, 4, 0, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_6)
{
    vector<int> test = {1, 2, 3, 0, 1, 0};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_7)
{
    vector<int> test = {1, 2, 1, 2, 3, 0, 1, 0};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_8)
{
    vector<int> test(1, 1000);
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_9)
{
    vector<int> test = {1, 2, 0, 0, 0, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_10)
{
    vector<int> test = {1, 0, 0, 0, 2, 0, 0, 0, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_11)
{
    vector<int> test = {1, 0, 0, 0, 2, 0, 0, 0, 1};
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_12)
{
    vector<int> test = {1, 2, -10, -8, -7};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
