#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

#include <cstddef>

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

        Node* _next;
        T _val;
    };

public:

    /**
     * @brief Construct a signly linked list
     */
    SinglyLinkedList(): _root(NULL) { /* DO NOTHING */ }
    
    /**
     * @brief Destruct a signly linked list
     * @details Destruct nodes from head to tail.
     */
    ~SinglyLinkedList()
    {
        Node* p = _root, next_p;
        
        while (p) {
            next_p = p->_next;
            delete p;
            p = next_p;
        }
    }

    Node* _root;
};

#endif /* !SINGLE_LINKED_LIST_H_ */