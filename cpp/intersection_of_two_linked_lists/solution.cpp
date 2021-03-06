#include "solution.h"

/**
 * @brief Marked the traversed node by modifing node->next
 * @score Daily-challenge (runtime / memory) (32.68% / 95.78%)
 * @score Linked-List     (runtime / memory) (13.15% / 68.08%)
 * @time-complexity O(N + M). N and M represent the length of listA and listB.
 * @space-complexity O(1).
 */
ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ans = NULL, *a = headA, *b = headB;

    while (a || b) {
        if (a && isMarked(a)) {
            ans = a; break;
        }

        if (a) {
            a = markNode(a);
        }

        if (b && isMarked(b)) {
            ans = b; break;
        }

        if (b) {
            b = markNode(b);
        }
    }

    cleanMarks(headA);
    cleanMarks(headB);
    return ans;
}

inline bool Solution::isMarked(ListNode *node)
{
    return (size_t)node->next & (size_t)MARKER;
}

inline void Solution::cleanMarks(ListNode *node)
{
    while (node && isMarked(node)) {
        node->next = (ListNode *)((size_t)node->next & (~((size_t)MARKER)));
        node = node->next;
    }
}

inline ListNode* Solution::markNode(ListNode *node)
{
    ListNode *next = node->next;

    node->next = (ListNode *)((size_t)(node->next) | (size_t)(MARKER));

    return next;
}