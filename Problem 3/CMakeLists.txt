cmake_minimum_required(VERSION 3.28)
project(Problem_3)

set(CMAKE_CXX_STANDARD 23)

add_executable(Problem_3 main.cpp
        SortedLinkedList/SortedLinkedList.h
        SortedLinkedList/SortedLinkedList.cpp
        SortedLinkedList/Node/Node.h
        SortedLinkedList/Node/Node.cpp
        SortedLinkedList/SortedLinkedList.cpp
        SortedLinkedList/SortedLinkedList.h)
