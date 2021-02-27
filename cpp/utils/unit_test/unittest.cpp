#include "gtest/gtest.h"
#include "list/singlyLinkedList.h"

using namespace std;

class TEST_SinglyLinkedList: public ::testing::Test
{
    static void TestSuiteSetUp() {}
    static void TestSuiteTearDown() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(TEST_SinglyLinkedList, addElements)
{
    SinglyLinkedList<int> list;
    
    list.addAtTail(0);
    EXPECT_EQ(list.get(0), 0);
    
    list.addAtHead(1);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 0);

    list.addAtTail(2);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 0);
    EXPECT_EQ(list.get(2), 2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
