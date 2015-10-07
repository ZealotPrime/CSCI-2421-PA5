cmake_minimum_required(VERSION 3.3)
project(CSCI_2421_PA5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Bag.h
    DynamicArray.cpp
    DynamicArray.h
    LinkedList.h
    main.cpp)

add_executable(CSCI_2421_PA5 ${SOURCE_FILES})