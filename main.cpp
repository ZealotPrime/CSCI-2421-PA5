//
// Created by zealot on 10/5/15.
//
#include <iostream>
#include "DynamicArray.h"



using namespace std;

int main()
{
    CSCI2421::DynamicArray testArray(21);

    testArray.print();
    for(int x=0;x<12;x++)
        testArray.push_back(x);
    testArray.print();
    cout<<"size of array is now: "<<testArray.size()<<endl;
    cout<<"capacity is now: "<<testArray.capacity()<<endl;

    for(int x=0;x<12;x++)
        testArray.insert(5,5);

    testArray.print();
    cout<<"size of array is now: "<<testArray.size()<<endl;
    cout<<"capacity is now: "<<testArray.capacity()<<endl;

    testArray.erase(5);

    testArray.print();
    cout<<"size of array is now: "<<testArray.size()<<endl;
    cout<<"capacity is now: "<<testArray.capacity()<<endl;

    cout<<"element at index 12: "<<testArray.get(12);

    return 0;
}