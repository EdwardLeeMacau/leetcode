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