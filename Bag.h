//
// Created by ericg on 9/29/2015.
//

#ifndef PA5_BAG_H
#define PA5_BAG_H

#include <cstdlib>
#include <ostream>

namespace CSCI2421
{
    template<typename T>
    class Bag
    {
    public:


        // Initializes the Bag
        // Postcondition: Bag is initialized
        Bag(const std::size_t initialCapacity = 20);

        // Copy Constructor
        // Postcondition: Bag is a copy of source with it's own dynamic memory
        Bag(const Bag &source);

        // Destructor for Bag. Frees up dynamic memory
        ~Bag();

        // inserts an element into the Bag
        // Precondition: size() < CAPACITY
        // Postcondition: A new copy of entry has been added to the Bag
        void insert(const T &x);

        // attempts to remove one element that is equal to x from the Bag.
        // Returns: true if the element was removed, else false. \
        // Precondition: none
        // Postcondition: one element that is equal to x is removed from the Bag.
        bool erase_one(const T &x);

        // erases every element that is equal to x from the Bag.
        // Returns: the number of elements erased
        // Precondition: none
        // Postcondition: all the elements that are equal to x are removed from the Bag
        std::size_t erase(const T &x);

        // returns the number of elements in the bag
        // Precondition: none
        // Postcondition: none
        std::size_t size() const;

        // returns the number of elements equal to x in the Bag
        // Precondition: none
        // Postcondition: none
        std::size_t count(const T &x) const;

        // returns the current maximum capacity of the Bag
        std::size_t capacity () const;

        // print the contents of the Bag
        void print();

        // overloaded assignment operator deallocates m_Data and allocates new memory for m_Data
        // and copies the elements from source to m_Data
        void operator=(const Bag &source);

    private:

        // if newCapacity > m_CurrentCapacity, allocates an array with size newCapacity
        // on the Heap, copies all elements from m_Data to the new array, deallocates the
        // old array memory and assigns m_Data to the new array.
        void resizeArray(const std::size_t newCapacity);

        // the number of elements currently in the Bag
        std::size_t m_NumberOfElements;

        // The max capacity of the Bag before it must be resized to accept more elements
        std::size_t m_CurrentCapacity;

        // where the Bag stores it's elements
        T *m_Data;
    };
}

#include "Bag.cpp"
#endif //PA5_BAG_H