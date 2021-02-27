#include "matrix.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test 
{

};

TEST_F(SolutionTest, test_0)
{
    Matrix<int> grid(0, 2, 2);    
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
