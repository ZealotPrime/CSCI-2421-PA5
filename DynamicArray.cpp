//
// Created by zealot on 10/5/15.
//

#include "DynamicArray.h"
#include <cassert>
#include <algorithm>
#include <iostream>

CSCI2421::DynamicArray::DynamicArray(std::size_t initialSize)
{
    m_Data = new value_type[initialSize];
    m_currentSize=initialSize;
    m_NumberOfElements=0;
}

void CSCI2421::DynamicArray::push_back(const value_type &x)
{
    if(m_currentSize<=m_NumberOfElements)
        resizeArray();
    m_Data[m_NumberOfElements++] = x;
}


void CSCI2421::DynamicArray::insert(const std::size_t position, const CSCI2421::DynamicArray::value_type &x)
{
    if(m_currentSize<=m_NumberOfElements)
        resizeArray();
    assert (position < m_NumberOfElements);

    std::copy_backward(m_Data + position, m_Data + m_NumberOfElements, m_Data + m_NumberOfElements +1);

    m_Data[position] = x;
    m_NumberOfElements++;
}

void CSCI2421::DynamicArray::erase(const std::size_t position)
{
    assert (position < m_NumberOfElements);

    std::copy(m_Data + position + 1, m_Data + m_NumberOfElements, m_Data + position );

    m_NumberOfElements --;
}

CSCI2421::DynamicArray::value_type CSCI2421::DynamicArray::get(const std::size_t position) const
{
    assert (position < m_NumberOfElements);
    return m_Data[position];
}

std::size_t CSCI2421::DynamicArray::size() const
{
    return m_NumberOfElements;
}

void CSCI2421::DynamicArray::print()
{
    std::cout << "DynamicArray contains " << m_NumberOfElements << " elements: ";

    for (std::size_t i = 0; i < m_NumberOfElements; i++)
    {
        std::cout << m_Data[i] << " ";
    }
    std::cout << std::endl;
}

std::size_t CSCI2421::DynamicArray::capacity() const
{
    return m_currentSize;
}

void CSCI2421::DynamicArray::resizeArray()
{
    m_currentSize*=2;
    value_type* expandedArray = new value_type[m_currentSize];
    std::copy(m_Data,m_Data+m_NumberOfElements,expandedArray);
    delete[] m_Data;
    m_Data=expandedArray;
}
