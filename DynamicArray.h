//
// Created by zealot on 10/5/15.
//

#ifndef PA5_ARRAY_H
#define PA5_ARRAY_H

#include <cstdlib>

namespace CSCI2421
{
    class DynamicArray
    {
    public:
        typedef int value_type;

        // constructs an Array
        // Precondition: none
        // Postcondition: Array is initialized
        DynamicArray(std::size_t=10);

        //copy constructor
        DynamicArray(const CSCI2421::DynamicArray&);

        //assignment operator
        void operator=(const CSCI2421::DynamicArray&);

        // inserts an element into the end of the array
        // Precondition: m_NumberOfElements < MAX_CAPACITY
        void push_back(const value_type &x);

        // inserts an element at the specified position in the Array, maintaining the order of the elements
        // Precondition: position < m_NumberOfElements
        // Precondition: m_NumberOfElements < MAX_CAPACITY
        void insert(const std::size_t position, const value_type &x);

        // removes the element at the specified position in the Array.
        // Precondition: position < m_NumberOfElements
        void erase(const std::size_t position);

        // returns the number of elements in the Array
        // Precondition: none
        std::size_t size() const;


        // returns the current capacity of the Array
        // Precondition: none
        std::size_t capacity() const;

        // returns the element at the specified position in the Array
        // Precondition: position < m_NumberOfElements
        value_type get(const std::size_t position) const;

        // print the contents of the Array
        void print();

    private:
        // the number of elements in the Array
        std::size_t m_NumberOfElements;

        //current size of the array
        std::size_t m_currentSize;

        // the statically allocated array
        value_type* m_Data;

        //function to resize the array if it fills up
        void resizeArray();
    };
}

#endif //PA5_ARRAY_H