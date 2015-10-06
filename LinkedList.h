//
// Created by ericg on 9/28/2015.
//

#ifndef PA5_LINKEDLIST_H
#define PA5_LINKEDLIST_H

#include <cstdlib>
namespace CSCI2421
{
    template <typename T>
    class LinkedList
    {
    public:
        // Constructor for LinkedList
        LinkedList();

        // Copy Constructor
        LinkedList(const LinkedList &other);

        // assignment operator
        LinkedList &operator=(const LinkedList &other);

        // destructor. Calls clear() to free up memory
        ~LinkedList();

        // Inserts a new element at the front of the list
        void insertAtFront(const T& data);

        // Inserts a new element at the end of the list
        void insertAtEnd(const T& data);

        // removes the element at the front of the list
        void removeAtFront();

        // returns the number of elements in the list
        std::size_t size();

        // removes all elements from the list.
        void clear();

        // prints the list to standard output
        void print();

    private:
        // internal data structure for linked list
        class Node
        {
        public:
            // holds the value of the node
            T m_Data;

            // holds a pointer to the next node in the linked list
            Node *m_Next;
        };

        // A pointer to the first Node in the list
        Node *m_Head;

        // A pointer to the last Node in the list
        Node *m_Tail;

        // The size of the list
        std::size_t m_Size;

    };
}
#include "LinkedList.cpp"


#endif //PA5_LINKEDLIST_H