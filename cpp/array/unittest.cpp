#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
	Solution sol;
	int i;
	
	vector<int> test0 = {0, 1, 2, 3, 4};
	vector<int> ans0 = {0, 1, 4, 9, 16};
	vector<int> ret0 = sol.sortedSquares(test0);
	for (i = 0; i < test0.size(); ++i) {
		EXPECT_EQ(ans0[i], ret0[i]);
	}
	
	vector<int> test1 = {-2, -1, 0, 1, 2};
	vector<int> ans1 = {0, 1, 1, 4, 4};
	vector<int> ret1 = sol.sortedSquares(test1);
	for (i = 0; i < test1.size(); ++i) {
		EXPECT_EQ(ans1[i], ret1[i]);
	}

	vector<int> test2 = {-4, -3, -2, -1, 0};
	vector<int> ans2 = {0, 1, 4, 9, 16};
	vector<int> ret2 = sol.sortedSquares(test2);
	for (i = 0; i < test2.size(); ++i) {
		EXPECT_EQ(ans2[i], ret2[i]);
	}
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}