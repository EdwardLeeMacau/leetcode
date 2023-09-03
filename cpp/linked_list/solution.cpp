#include "solution.h"

/**
 * @score (runtime / memory) (100.00% / 86.69%)
 */
int getDecimalValue(ListNode *head)
{
    int val = 0;

    while (head) {
        val <<= 1;
        val += head->val;
        head = head->next;
    }

    return 0;
}

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
 * @time-complexity  O(N). N stand for the length of linked list
 * @space-complexity O(1).
 */
bool Solution::isPalindrome(ListNode *head)
{
    ListNode dummy(0, head), *node, *second;
    int length = 0;

    node = &dummy;
    while ((node = node->next)) {
        ++length;
    }

    node = head;
    length /= 2;
    for (; length; --length) {
        node = node->next;
    }

    second = reverseList(node->next);
    while (node && second) {
        if (node->val != second->val) {
            return false;
        }
        node = node->next; second = second->next;
    }

    return true;
}

/**
 * @score (runtime / memory) (61.47% / 45.30%)
 * @time-complexity  O(N).
 * @space-complexity O(1).
 */
ListNode* swapPairs(ListNode *head)
{
    ListNode dummy(0, head), *prev, *next;

    prev = &dummy;

    while (head && (next = head->next)) {
        // Link to the next node
        prev->next = next;

        // Reverse the node
        head->next = next->next;
        next->next = head;

        // Move forward
        prev = head; head = head->next;
    }

    return dummy.next;
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
 * @brief Add the numbers in 2 lists without using extra memory
 * @score (runtime / memory) (77.70% / 98.62%)
 * @param[in] l1, l2    pointer to the list head
 */
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy1(0, l1), dummy2(0, l2);
    int carry = 0;

    l1 = &dummy1; l2 = &dummy2;
    do {
        l1 = l1->next; l2 = l2->next;

        l1->val += l2->val + carry;
        carry = l1->val / 10;
        l1->val %= 10;
    } while ((l1->next) && (l2->next));

    if (l2->next) {
        l1->next = l2->next;
    }

    while (carry && l1->next) {
        l1 = l1->next;

        l1->val += carry;
        carry = l1->val / 10;
        l1->val %= 10;
    }

    if (carry) {
        l1->next = new ListNode(1, NULL);
    }

    return dummy1.next;
}

/**
 * @brief Merge 2 ordered lists (ascending) without using any extra memory
 * @param[in] l1, l2    pointer to the list head
 */
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0, NULL);
    ListNode *node = &dummy;

    while (l1 && l2) {
        if (l1->val > l2->val) {
            node = node->next = l2; l2 = l2->next;
        } else {
            node = node->next = l1; l1 = l1->next;
        }
    }

    node->next = (!l1)? l2: l1;

    return dummy.next;
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

/**
 * @param[in] from    node start to delete
 * @param[in] to      node stop to delete (exclusive)
 */
inline void Solution::deleteListNodes(ListNode *from, ListNode *to)
{
    ListNode *node;

    while ((node = from) != to) {
        from = node->next; delete node;
    }

    return;
}

/**
 * @brief Delete duplicated elements from a sorted singly linked list
 * @score (runtime / memory) (84.54% / 82.40%)
 * @time-complexity  O(N)
 * @space-complexity O(1)
 */
ListNode* Solution::deleteDuplicates(ListNode* head)
{
    ListNode dummy(0, head), *slow_p, *fast_p;
    int val;

    slow_p = &dummy; val = slow_p->val;
    while ((fast_p = slow_p->next)) {
        val = fast_p->val;

        do {
            while (fast_p->next && (val == fast_p->next->val)) {
                fast_p = fast_p->next;
            }

            if (fast_p == slow_p->next) {
                break;
            }

            /** Delete the duplicates nodes */
            fast_p = fast_p->next; deleteListNodes(slow_p->next, fast_p); slow_p->next = fast_p;

            if (!fast_p) {
                return dummy.next;
            }

            val = fast_p->val;
        } while (true);

        slow_p = slow_p->next;
    }

    return dummy.next;
}

/**
 * @brief utils function for Solution::getIntersectionNode
 */
inline bool Solution::isMarked(ListNode *node)
{
    return (size_t)node->next & (size_t)MARKER;
}

/**
 * @brief utils function for Solution::getIntersectionNode
 */
inline void Solution::cleanMarks(ListNode *node)
{
    while (node && isMarked(node)) {
        node->next = (ListNode *)((size_t)node->next & (~((size_t)MARKER)));
        node = node->next;
    }
}

/**
 * @brief utils function for Solution::getIntersectionNode
 */
inline ListNode* Solution::markNode(ListNode *node)
{
    ListNode *next = node->next;

    node->next = (ListNode *)((size_t)(node->next) | (size_t)(MARKER));

    return next;
}

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