#include "solution.h"
#include "gtest/gtest.h"

#include <iostream>

using namespace std;

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;

    vector<int> test0 = {30, 20, 150, 100, 40};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test0), 3);

    vector<int> test1 = {30, 30, 30};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test1), 3);

    vector<int> test2 = {1, 2, 3};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test2), 0);

    vector<int> test3 = {10, 20, 30, 40, 50, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test3), 2);

    vector<int> test4 = {60, 60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test4), 3);
    
    vector<int> test5 = {60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test5), 1);
    
    vector<int> test6 = {60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test6), 0);
    
    vector<int> test7 = {60, 60, 60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test7), 6);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
