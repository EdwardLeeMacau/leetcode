#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <cstddef>

template<class T>
class DoublyLinkedList
{
private:

    class Node {
    public:

        /**
         * @brief Construct a node in doubly linked list
         */
        Node()
            : _prev(NULL), _next(NULL), _val() { /* DO NOTHING */ }

        /**
         * @brief Construct a node in doubly linked list
         * @param[in] t    value to store in this node
         */
        Node(const T& t)
            : _prev(NULL), _next(NULL), _val(t) { /* DO NOTHING */ }

        /**
         * @brief Construct a node in doubly linked list
         * @param[in] prev    pointer to previous node
         * @param[in] next    pointer to next node
         */
        Node(Node* prev, Node* next)
            : _prev(prev), _next(next), _val() { /* DO NOTHING */ }

        /**
         * @brief Construct a node in doubly linked list
         * @param[in] prev    pointer to previous node
         * @param[in] next    pointer to next node
         * @param[in] t       value to store in this node
         */
        Node(Node* prev, Node* next, const T& t)
            : _prev(prev), _next(next), _val(t) { /* DO NOTHING */ }

        /**
         * @brief Destruct a node
         */
        ~Node() { /* DO NOTHING */ }

        Node* _prev;
        Node* _next;
        T _val;
    };

    Node* _head;
    Node* _tail;

public:

    DoublyLinkedList() 
    {
        // TODO
    }
    ~DoublyLinkedList()
    {
        // TODO
    }

    void push_back(const T& t)
    {
        // TODO
    }
};

#endif /* !DOUBLY_LINKED_LIST_H_ */