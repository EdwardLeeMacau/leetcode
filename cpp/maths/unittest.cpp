#include "solution.h"
#include "gtest/gtest.h"

class SolutionTest : public ::testing::Test {

};

class SumZeroTest : public ::testing::TestWithParam<int> {

};

int sum(const std::vector<int>& ary)
{
    int ret = 0;
    for (size_t idx = 0; idx < ary.size(); ++idx) {
        ret += ary[idx];
    }
    return ret;
}

TEST_P(SumZeroTest, test)
{
    Solution sol;

    EXPECT_EQ(sum(sol.sumZero(GetParam())), 0);
}

INSTANTIATE_TEST_SUITE_P(Instantiation,
                         SumZeroTest,
                         ::testing::Range(1, 10));

TEST_F(SolutionTest, test_0)
{
    Solution sol;

    std::vector<int> test0 = {30, 20, 150, 100, 40};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test0), 3);

    std::vector<int> test1 = {30, 30, 30};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test1), 3);

    std::vector<int> test2 = {1, 2, 3};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test2), 0);

    std::vector<int> test3 = {10, 20, 30, 40, 50, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test3), 2);

    std::vector<int> test4 = {60, 60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test4), 3);

    std::vector<int> test5 = {60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test5), 1);

    std::vector<int> test6 = {60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test6), 0);

    std::vector<int> test7 = {60, 60, 60, 60};
    EXPECT_EQ(sol.numPairsDivisibleBy60(test7), 6);
}

TEST_F(SolutionTest, test_1)
{
    Solution sol;

    std::vector<int> test0 = {1, 1, 2, 3};
    EXPECT_EQ(sol.distributeCandies(test0), 2);
}

TEST_F(SolutionTest, test_2)
{
    Solution sol;

    std::vector<int> test1 = {1, 1};
    EXPECT_EQ(sol.distributeCandies(test1), 1);
}

TEST_F(SolutionTest, test_3)
{
    Solution sol;

    std::vector<int> test2 = {1, 1, 1, 1, 1, 1};
    EXPECT_EQ(sol.distributeCandies(test2), 1);
}

TEST_F(SolutionTest, test_4)
{
    Solution sol;
    std::vector<int> test = {1, 2, 3, 4, 5};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_5)
{
    Solution sol;
    std::vector<int> test = {5, 4, 3, 2, 1};
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_6)
{
    Solution sol;
    std::vector<int> test = {2, 1, 5, 0, 4, 6};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_7)
{
    Solution sol;
    std::vector<int> test = {2, 2, 3, 0, 2, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_8)
{
    Solution sol;
    std::vector<int> test = {1, 2};
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_9)
{
    Solution sol;
    std::vector<int> test = {2, 2, 3, 0, 2, 4, 0, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_10)
{
    Solution sol;
    std::vector<int> test = {1, 2, 3, 0, 1, 0};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_11)
{
    Solution sol;
    std::vector<int> test = {1, 2, 1, 2, 3, 0, 1, 0};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_12)
{
    Solution sol;
    std::vector<int> test(1, 1000);
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_13)
{
    Solution sol;
    std::vector<int> test = {1, 2, 0, 0, 0, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_14)
{
    Solution sol;
    std::vector<int> test = {1, 0, 0, 0, 2, 0, 0, 0, 3};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

TEST_F(SolutionTest, test_15)
{
    Solution sol;
    std::vector<int> test = {1, 0, 0, 0, 2, 0, 0, 0, 1};
    EXPECT_EQ(sol.increasingTriplet(test), false);
}

TEST_F(SolutionTest, test_16)
{
    Solution sol;
    std::vector<int> test = {1, 2, -10, -8, -7};
    EXPECT_EQ(sol.increasingTriplet(test), true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
