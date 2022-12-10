cmake_minimum_required(VERSION 3.19)
project(C__DataStructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__DataStructures main.cpp sqlist/sqlist.cpp sqlist/sqlist.h linklist/linklist.cpp linklist/linklist.h stack/mystack.cpp stack/mystack.h queue/myqueue.cpp queue/myqueue.h string/mystring.cpp string/mystring.h binarytree/binarytree.cpp binarytree/binarytree.h find/binarynode.cpp find/binarynode.h)