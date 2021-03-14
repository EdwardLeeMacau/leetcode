#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head);
    bool isPalindrome(ListNode *head);
    ListNode* reverseList(ListNode *head);
    ListNode* detectCycle(ListNode *head);
    ListNode* oddEvenList(ListNode *head);
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2);
    ListNode* removeElements(ListNode *head, int val);
    ListNode* removeNthFromEnd(ListNode *head, int n);
};

#endif /* !SOLUTION_H_ */
