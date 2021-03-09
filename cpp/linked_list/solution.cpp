#include "solution.h"

/**
 * @brief Solved the problem by Floyd's cycle-finding algorithm.
 * @score (runtime / memory) (7.22% / 21.89%)
 * @time-complexity  O(N). N stand for the length of linked list
 * @space-complexity O(1).
 */
bool Solution::hasCycle(ListNode *head)
{
    ListNode *fast_p, *slow_p;
    fast_p = slow_p = head;

    if (!head) {
        return false;
    }

    do {
        if (!(fast_p->next) || !(fast_p->next->next)) {
            return false;
        }

        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
    } while (fast_p != slow_p);

    return true;
}

/**
 * @brief
 * @score (runtime / memory) (72.20% / 61.62%)
 * @time-complexity  O(N). N stand for the length of linked list
 * @space-complexity O(1).
 */
ListNode* Solution::reverseList(ListNode *head)
{
    if (!head) {
        return NULL;
    }

    ListNode *next = head->next, *buf = NULL, *cur = head;

    do {
        next = cur->next;
        cur->next = buf;
        buf = cur;
    } while ((cur = next));

    return buf;
}

/**
 * @brief Make the linked list ordered by odd then even.
 * Example: [1, 2, 3, 4, 5] -> [1, 3, 5, 2, 4]
 * @details Keep tracking when we find the tail of the origin list.
 * Delete the next pointer in the last even node when need
 * @score (runtime / memory) (95.51% / 66.30%)
 * @param[in] head    pointer to the list head
 * @param[in] val     value to remove from list
 */
ListNode* Solution::oddEvenList(ListNode *head)
{
    ListNode *odd, *even, *evenHead;
    
    /* Case if length is equal to 0 */
    if (!head) {
        return NULL;
    }

    /* Case if length is larger or equal to 1 */ 
    odd = head; 
    even = evenHead = odd->next;

    while (odd && even) {
        if (even->next) {
            odd->next = even->next; odd = odd->next;
        } else {
            break;
        }

        if (odd->next) {
            even->next = odd->next; even = even->next;
        } else {
            break;
        }
    }

    odd->next = evenHead;
    if (even) {
        even->next = NULL;
    }

    return head;
}

/**
 * @brief Scan the list. Take care of cases need to delete head / tail
 * @score (runtime / memory) (91.13% / 54.36%)
 * @param[in] head    pointer to the list head
 * @param[in] val     value to remove from list
 */
ListNode* Solution::removeElements(ListNode *head, int val)
{
    ListNode *cur = head, *next;

    while (head && (head->val == val)) {
        head = head->next; delete cur; cur = head;
    }

    if (!cur) {
        return NULL;
    }

    while (cur && (next = cur->next)) {
        while (next && (next->val == val)) {
            cur->next = next->next; delete next; next = cur->next;
        }
        cur = next;
    }

    return head;
}

/**
 * @brief Maintain two pointers, one with a delay of n steps.
 * @score (runtime / memory) (32.51% / 75.53%)
 * @param[in] head    pointer to the list head
 * @param[in] n       nth node from end to remove
 */
ListNode* Solution::removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast_p, *slow_p;
    ListNode *dummy = new ListNode(0, head);

    /** n <- n + 1 to find the previous of the target node */
    n += 1;
    fast_p = slow_p = dummy;
    for (; n > 0; --n) {
        fast_p = fast_p->next;
    }

    while (fast_p) {
        fast_p = fast_p->next;
        slow_p = slow_p->next;
    }

    /** fast_p is no used now. Use it to mark the memory to free */
    fast_p = slow_p->next;
    slow_p->next = fast_p->next;

    head = dummy->next;
    delete fast_p;
    delete dummy;

    return head;
}

/**
 * @brief Solved the problem by Floyd's cycle-finding algorithm.
 * @score (runtime / memory) (81.25% / 57.50%)
 * @time-complexity  O(N). N stand for the length of linked list
 * @space-complexity O(1).
 */
ListNode* Solution::detectCycle(ListNode *head)
{
    ListNode *fast_p, *slow_p;
    int loop_length = 1;
    fast_p = slow_p = head;

    if (!head) {
        return NULL;
    }

    /** Check if cycle is exist */
    do {
        if (!(fast_p->next) || !(fast_p->next->next)) {
            return NULL;
        }

        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
    } while (fast_p != slow_p);

    /** Find length of the loop */
    fast_p = fast_p->next;
    while (fast_p != slow_p) {
        ++loop_length; fast_p = fast_p->next;
    }

    /** slow_p walk N steps. fast_p walk N + L steps */
    fast_p = slow_p = head;
    for (; loop_length > 0; --loop_length)  {
        fast_p = fast_p->next;
    }

    while (fast_p != slow_p) {
        fast_p = fast_p->next;
        slow_p = slow_p->next;
    }

    /** slow_p and fast_p point to the starting point of the loop */
    return fast_p;
}