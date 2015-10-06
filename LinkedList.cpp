#include <iostream>
#include "LinkedList.h"

template<typename T>
CSCI2421::LinkedList<T>::LinkedList() : m_Head(NULL), m_Tail(NULL), m_Size(0)
{

}

template<typename T>
CSCI2421::LinkedList<T>::LinkedList(const CSCI2421::LinkedList<T> &other) : m_Head(NULL), m_Tail(NULL), m_Size(0)
{
    Node* current = other.m_Head;
    while (current != NULL)
    {
        insertAtEnd(current->m_Data);
        current = current->m_Next;
    }
}

template<typename T>
CSCI2421::LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
CSCI2421::LinkedList<T>& CSCI2421::LinkedList<T>::operator=(const CSCI2421::LinkedList<T> &source)
{
    if (this == &source)
        return *this;

    clear();

    Node* current = source.m_Head;
    while (current != NULL)
    {
        insertAtEnd(current->m_Data);
        current = current->m_Next;
    }

    return *this;
}

template<typename T>
void CSCI2421::LinkedList<T>::insertAtFront(const T& data)
{
    Node* newNode = new Node();
    newNode->m_Data = data;
    newNode->m_Next = m_Head;

    if (m_Head == NULL)
        m_Tail = newNode;

    m_Head = newNode;
    m_Size++;
}

template<typename T>
void CSCI2421::LinkedList<T>::insertAtEnd(const T& data)
{
    if (m_Tail == NULL)
    {
        insertAtFront(data);
    }
    else
    {
        Node* newNode = new Node();
        newNode->m_Data = data;
        newNode->m_Next = NULL;
        m_Tail->m_Next = newNode;
        m_Tail = newNode;
        m_Size++;
    }
}

template<typename T>
void CSCI2421::LinkedList<T>::removeAtFront()
{
    if (m_Head != NULL)
    {
        Node* delPtr = m_Head;
        m_Head = m_Head->m_Next;

        if (m_Head == NULL)
            m_Tail = NULL;

        delete delPtr;
        m_Size--;
    }
}


template<typename T>
std::size_t CSCI2421::LinkedList<T>::size()
{
    return m_Size;
}

template<typename T>
void CSCI2421::LinkedList<T>::clear()
{
    while (m_Head != NULL)
    {
        removeAtFront();
    }
    m_Size = 0;
}

template<typename T>
void CSCI2421::LinkedList<T>::print()
{
    std::cout << "LinkedList contains " << m_Size << " elements: ";

    const Node* current = m_Head;
    while (current != NULL)
    {
        std::cout << current->m_Data << " ";
        current = current->m_Next;
    }
    std::cout << std::endl;
}




