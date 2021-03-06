#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <unistd.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    #define MARKER 0x1

private:
    inline bool isMarked(ListNode *node);
    inline void cleanMarks(ListNode *node);
    inline ListNode* markNode(ListNode *node);

public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB);
};

#endif /* !SOLUTION_H_ */
