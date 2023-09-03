#include <iostream>

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

TEST_F(TEST_SinglyLinkedList, addElements_0)
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

    list.addAtIndex(2, 3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 0);
    EXPECT_EQ(list.get(2), 3);
    EXPECT_EQ(list.get(3), 2);
}

TEST_F(TEST_SinglyLinkedList, addElements_1)
{
    SinglyLinkedList<int> list;

    list.addAtIndex(0, 3);
    EXPECT_EQ(list.get(0), 3);
}

TEST_F(TEST_SinglyLinkedList, deleteElements_0)
{
    SinglyLinkedList<int> list;

    list.addAtHead(2);
    list.addAtHead(3);
    list.addAtHead(0);
    list.addAtHead(1);

    list.deleteAtIndex(0);
    EXPECT_EQ(list.get(0), 0);

    list.deleteAtIndex(2);
    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 3);

    list.deleteAtIndex(1);
    EXPECT_EQ(list.get(0), 0);
}

TEST_F(TEST_SinglyLinkedList, combination_0)
{
    SinglyLinkedList<int> list;

    list.addAtHead(2);
    list.deleteAtIndex(1);
    list.addAtHead(2);
    list.addAtHead(7);
    list.addAtHead(3);
    list.addAtHead(2);
    list.addAtHead(5);
    list.addAtTail(5);
    EXPECT_EQ(list.get(5), 2);
    list.deleteAtIndex(6);
    list.deleteAtIndex(4);
}

TEST_F(TEST_SinglyLinkedList, combination_1)
{
    SinglyLinkedList<int> list;

    list.addAtHead(4);
    EXPECT_EQ(list.get(1), -1);
    EXPECT_EQ(list.get(0), 4);
    list.addAtHead(1);
    list.addAtHead(5);
    EXPECT_EQ(list.get(2), 4);
    list.deleteAtIndex(3);
    EXPECT_EQ(list.get(2), 4);
    list.addAtHead(7);
    EXPECT_EQ(list.get(3), 4);
    EXPECT_EQ(list.get(3), 4);
    EXPECT_EQ(list.get(3), 4);
    list.addAtHead(1);
    list.deleteAtIndex(4);
}

TEST_F(TEST_SinglyLinkedList, combination_2)
{
    SinglyLinkedList<int> list;

    list.addAtHead(1);
    list.deleteAtIndex(1);
    list.deleteAtIndex(1);
    list.addAtTail(7);
    list.deleteAtIndex(2);
    list.addAtTail(1);
    list.addAtTail(8);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 7);
    list.addAtHead(2);
    EXPECT_EQ(list.get(0), 2);
    list.addAtIndex(5, 2);
    list.addAtTail(7);
    EXPECT_EQ(list.get(2), 7);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
