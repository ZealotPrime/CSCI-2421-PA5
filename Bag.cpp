#include "Bag.h"

#include <algorithm>
#include <iostream>


CSCI2421::Bag::Bag(const std::size_t initialCapacity) : m_NumberOfElements(0), m_CurrentCapacity(initialCapacity)
{
    m_Data = new value_type[initialCapacity];
}

CSCI2421::Bag::Bag(const CSCI2421::Bag &source) : m_NumberOfElements(source.m_NumberOfElements),
                                                  m_CurrentCapacity(source.m_CurrentCapacity)
{
    m_Data = new value_type[m_CurrentCapacity];
    std::copy (source.m_Data, source.m_Data + m_NumberOfElements, m_Data);
}

CSCI2421::Bag::~Bag()
{
    delete[] m_Data;
}

void CSCI2421::Bag::insert(const value_type& x)
{
    if (m_NumberOfElements == m_CurrentCapacity)
    {
        resizeArray(m_NumberOfElements + 1);
    }
    m_Data[m_NumberOfElements] = x;
    m_NumberOfElements++;
}

bool CSCI2421::Bag::erase_one(const value_type& x)
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

std::size_t CSCI2421::Bag::erase(const value_type& x)
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

std::size_t CSCI2421::Bag::size() const
{
    return m_NumberOfElements;
}

std::size_t CSCI2421::Bag::count(const value_type& x) const
{
    std::size_t counter = 0;
    for (std::size_t i = 0; i < m_NumberOfElements; i++)
    {
        if (m_Data[i] == x)
            counter++;

    }
    return counter;

}

void CSCI2421::Bag::resizeArray(const std::size_t newCapacity)
{
    if (newCapacity <= m_CurrentCapacity)
    {
        // already large enough
        return;
    }

    value_type* largerArray = new value_type[newCapacity];
    std::copy (m_Data, m_Data + m_CurrentCapacity, largerArray);

    delete[] m_Data;
    m_Data = largerArray;
    m_CurrentCapacity = newCapacity;
}


void CSCI2421::Bag::operator=(const CSCI2421::Bag &source)
{
    if (this == &source)
        return;

    value_type* newData;

    if (m_CurrentCapacity != source.m_CurrentCapacity)
    {
        newData = new value_type[source.m_CurrentCapacity];
        delete[] m_Data;
        m_Data = newData;
        m_CurrentCapacity = source.m_CurrentCapacity;
    }

    m_NumberOfElements = source.m_NumberOfElements;
    std::copy (source.m_Data, source.m_Data + m_NumberOfElements, m_Data);

}

void CSCI2421::Bag::print()
{
    std::cout << "Bag contains " << m_NumberOfElements << " elements: ";
    for (std::size_t i = 0; i < m_NumberOfElements; i++)
    {
        std::cout << m_Data[i] << " ";
    }
    std::cout << std::endl;
}

size_t CSCI2421::Bag::capacity() const
{
    return m_CurrentCapacity;
}