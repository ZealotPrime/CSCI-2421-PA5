#include "Bag.h"
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    CSCI2421::Bag<string> tester;

    for(int x=0;x<10;x++)
        tester.insert("Test");

    tester.print();
    //tester.erase("Test");
    tester.print();

    CSCI2421::Bag<string> test2(tester);
    test2.print();
    test2.erase("Test");
    tester=test2;
    tester.print();



}