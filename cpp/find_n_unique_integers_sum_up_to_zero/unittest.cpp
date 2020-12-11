#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::TestWithParam<int> {

};

int sum(const vector<int>& ary) 
{
    int ret = 0;
    for (size_t idx = 0; idx < ary.size(); ++idx) {
        ret += ary[idx];
    }
    return ret;
}

TEST_P(SolutionTest, test)
{
    Solution sol;
    
    EXPECT_EQ(sum(sol.sumZero(GetParam())), 0);
}

INSTANTIATE_TEST_SUITE_P(Instantiation, 
                         SolutionTest, 
                         ::testing::Range(1, 10));

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}