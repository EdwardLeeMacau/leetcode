#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

#include <cstddef>

/**
 * @score (runtime / memory) (91.26% / 85.62%)
 */
template <class T>
class SinglyLinkedList
{
private:

    class Node {
    public:

        /**
         * @brief Construct a node in singly linked list
         */
        Node(): _next(NULL), _val() { /* DO NOTHING */ }

        /**
         * @brief Construct a node in doubly linked list
         * @param[in] t    value to store in this node
         */
        Node(const T& t): _next(NULL), _val(t) { /* DO NOTHING */ }

        /**
         * @brief Construct a node in doubly linked list
         * @param[in] next    pointer to next node
         */
        Node(Node* next): _next(next), _val() { /* DO NOTHING */ }

        /**
         * @brief Construct a node in doubly linked list
         * @param[in] next    pointer to next node
         * @param[in] t       value to store in this node
         */
        Node(Node* next, const T& t): _next(next), _val(t) { /* DO NOTHING */ }

        /**
         * @brief Destruct a node
         */
        ~Node() { /* DO NOTHING */ }

        Node *_next;
        T _val;
    };

    Node *_head;

public:

    /**
     * @brief Construct a signly linked list
     */
    SinglyLinkedList(): _head(NULL) { /* DO NOTHING */ }

    /**
     * @brief Destruct a signly linked list
     * @details Destruct nodes from head to tail.
     */
    ~SinglyLinkedList()
    {
        Node *p, *next_p;

        p = _head;
        while (p) {
            next_p = p->_next;
            delete p;
            p = next_p;
        }
    }

    class iterator {

    };

    /**
     * @notes For better interface design, return type T& should be changed to iterator::end.
     */
    int get(int index) const
    {
        Node *p = _head;

        for (; p && (index > 0); --index) {
            p = p->_next;
        }

        return p? p->_val: -1;
    }

    void addAtHead(const T& val)
    {
        _head = new Node(_head, val);
    }

    void addAtTail(const T& val)
    {
        Node *p = _head;

        if (!_head) {
            _head = new Node(val);
            return;
        }

        while (p->_next) {
            p = p->_next;
        }

        p->_next = new Node(val);
    }

    /**
     * @details This method should handle 3 cases.
     * @param[in] index    node to delete
     * @complexity O(N), N is the index
     * 1. Add the 0th node (_head). List member _head should be changes
     * 2. Add the non-existing node (invalid index). Ingore this action
     * 3. Add the other node. The previous node should be handled.
     */
    void addAtIndex(int index, const T& val)
    {
        Node *prev = _head;

        // Case 1: Add to 0th node
        if (!index) {
            _head = new Node(_head, val);
            return;
        }

        // Case 2: Invalid index
        for (; prev && (index > 1); --index) {
            prev = prev->_next;
        }

        if (index > 1) {
            return;
        }

        // Case 3: Valid index
        Node *cur = new Node(prev->_next, val);
        prev->_next = cur;
    }

    /**
     * @details This method should handle 3 cases.
     * @param[in] index    node to delete
     * @complexity O(N), N is the index
     * 1. Delete the non-existing node (invalid index). Ingore this action
     * 2. Delete the 0th node (_head). List member _head should be changes
     * 3. Delete the other node. The previous node should be handled.
     */
    void deleteAtIndex(int index)
    {
        Node *prev = _head;

        // Case 2: Delete the 0th node (_head).
        if (!index) {
            _head = _head->_next;
            delete prev;
            return;
        }

        for (; prev && (index > 1); --index) {
            prev = prev->_next;
        }

        // Case 1: Delete the non-existing node (invalid index).
        if (index > 1) {
            return;
        }

        // Case 3: Delete the other node.
        Node *cur = prev->_next;
        
        if (cur) {
            prev->_next = cur->_next;
            delete cur;
        }

        return;
    }

};

#endif /* !SINGLE_LINKED_LIST_H_ */