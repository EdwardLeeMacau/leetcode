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


class Solution
{
    #define MARKER 0x1

private:
    inline bool isMarked(ListNode *node);
    inline void cleanMarks(ListNode *node);
    inline void deleteListNodes(ListNode *from, ListNode *to);
    inline ListNode* markNode(ListNode *node);

public:
    int getDecimalValue(ListNode *head);
    bool hasCycle(ListNode *head);
    bool isPalindrome(ListNode *head);
    ListNode* swapPairs(ListNode *head);
    ListNode* reverseList(ListNode *head);
    ListNode* detectCycle(ListNode *head);
    ListNode* oddEvenList(ListNode *head);
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2);
    ListNode* removeElements(ListNode *head, int val);
    ListNode* deleteDuplicates(ListNode *Shead);
    ListNode* removeNthFromEnd(ListNode *head, int n);
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);
};

#endif /* !SOLUTION_H_ */
