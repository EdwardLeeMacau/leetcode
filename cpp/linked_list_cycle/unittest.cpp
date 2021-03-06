#include <iostream>

#include "solution.h"
#include "gtest/gtest.h"

using namespace std;

class SolutionTest : public ::testing::Test {

};

TEST_F(SolutionTest, test_0)
{
    Solution sol;

    ListNode *head, *cur, *next;
    cur = head = new ListNode(0);

    next = new ListNode(1);
    cur->next = next;
    cur = next;

    next = new ListNode(2);
    cur->next = next;
    cur = next;

    cur->next = head->next; // Produce a cycle: {0, 1, 2}, 2 point to 1.

    EXPECT_TRUE(sol.hasCycle(head));
    EXPECT_EQ(sol.detectCycle(head), head->next);

    // Recycle memory: break the loop then recycle from head to tail.
    cur->next = NULL;
    cur = head;
    next = cur->next;

    while (cur) {
        next = cur->next; delete cur; cur = next;
    }
}

TEST_F(SolutionTest, test_1)
{
    Solution sol;

    ListNode *head, *cur, *next;
    cur = head = new ListNode(0);

    next = new ListNode(1);
    cur->next = next;
    cur = next;

    next = new ListNode(2);
    cur->next = next;
    cur = next;

    EXPECT_FALSE(sol.hasCycle(head));
    EXPECT_EQ(sol.detectCycle(head), static_cast<ListNode*>(NULL));

    // Recycle memory: break the loop then recycle from head to tail.
    cur = head;
    next = cur->next;

    while (cur) {
        next = cur->next; delete cur; cur = next;
    }
}

TEST_F(SolutionTest, test_2)
{
    Solution sol;

    ListNode *head, *cur, *next;
    cur = head = new ListNode(0);

    next = new ListNode(1);
    cur->next = next;
    cur = next;

    next = new ListNode(2);
    cur->next = next;
    cur = next;

    next = new ListNode(3);
    cur->next = next;
    cur = next;

    EXPECT_FALSE(sol.hasCycle(head));
    EXPECT_EQ(sol.detectCycle(head), static_cast<ListNode*>(NULL));

    // Recycle memory: break the loop then recycle from head to tail.
    cur = head;
    next = cur->next;

    while (cur) {
        next = cur->next; delete cur; cur = next;
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
