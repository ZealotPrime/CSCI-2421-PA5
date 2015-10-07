//#include "Bag.h"

#include <algorithm>
#include <iostream>

template<typename T>
CSCI2421::Bag<T>::Bag(const std::size_t initialCapacity) : m_NumberOfElements(0), m_CurrentCapacity(initialCapacity)
{
    m_Data = new T[initialCapacity];
}
template<typename T>
CSCI2421::Bag<T>::Bag(const CSCI2421::Bag &source) : m_NumberOfElements(source.m_NumberOfElements),
                                                  m_CurrentCapacity(source.m_CurrentCapacity)
{
    m_Data = new T[m_CurrentCapacity];
    std::copy (source.m_Data, source.m_Data + m_NumberOfElements, m_Data);
}
template<typename T>
CSCI2421::Bag<T>::~Bag()
{
    delete[] m_Data;
}

template<typename T>
void CSCI2421::Bag<T>::insert(const T& x)
{
    if (m_NumberOfElements == m_CurrentCapacity)
    {
        resizeArray(m_NumberOfElements + 1);
    }
    m_Data[m_NumberOfElements] = x;
    m_NumberOfElements++;
}

template<typename T>
bool CSCI2421::Bag<T>::erase_one(const T& x)
{
    for (std::size_t index = 0; index < m_NumberOfElements; index++)
    {
        if (m_Data[index] == x)
        {
            m_NumberOfElements--;
            m_Data[index] = m_Data[m_NumberOfElements];
            return true;
        }
    }
    return false;
}

template<typename T>
std::size_t CSCI2421::Bag<T>::erase(const T& x)
{
    std::size_t index = 0;
    std::size_t numberRemoved = 0;

    while (index < m_NumberOfElements)
    {
        if (m_Data[index] == x)
        {
            m_NumberOfElements--;
            m_Data[index] = m_Data[m_NumberOfElements];
            numberRemoved++;
        }
        else
        {
            index++;
        }
    }
    return numberRemoved;
}

template<typename T>
std::size_t CSCI2421::Bag<T>::size() const
{
    return m_NumberOfElements;
}

template<typename T>
std::size_t CSCI2421::Bag<T>::count(const T& x) const
{
    std::size_t counter = 0;
    for (std::size_t i = 0; i < m_NumberOfElements; i++)
    {
        if (m_Data[i] == x)
            counter++;

    }
    return counter;

}

template<typename T>
void CSCI2421::Bag<T>::resizeArray(const std::size_t newCapacity)
{
    if (newCapacity <= m_CurrentCapacity)
    {
        // already large enough
        return;
    }

    T* largerArray = new T[newCapacity];
    std::copy (m_Data, m_Data + m_CurrentCapacity, largerArray);

    delete[] m_Data;
    m_Data = largerArray;
    m_CurrentCapacity = newCapacity;
}

template<typename T>
void CSCI2421::Bag<T>::operator=(const CSCI2421::Bag &source)
{
    if (this == &source)
        return;

    T* newData;

    if (m_CurrentCapacity != source.m_CurrentCapacity)
    {
        newData = new T[source.m_CurrentCapacity];
        delete[] m_Data;
        m_Data = newData;
        m_CurrentCapacity = source.m_CurrentCapacity;
    }

    m_NumberOfElements = source.m_NumberOfElements;
    std::copy (source.m_Data, source.m_Data + m_NumberOfElements, m_Data);

}

template<typename T>
void CSCI2421::Bag<T>::print()
{
    std::cout << "Bag contains " << m_NumberOfElements << " elements: ";
    for (std::size_t i = 0; i < m_NumberOfElements; i++)
    {
        std::cout << m_Data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
size_t CSCI2421::Bag<T>::capacity() const
{
    return m_CurrentCapacity;
}