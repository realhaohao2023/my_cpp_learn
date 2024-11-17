cmake_minimum_required(VERSION 3.29)
project(my_cpp_learn)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_cpp_learn
    c/test.c
    c/test2.c
    c++/1.1namespace.cpp
    c++/1.2input_output.cpp
    c++/1.3Default_parameter.cpp
    c++/1.4FuncOverload.cpp
    c++/1.5reference.cpp
    c++/1.6auto.cpp
    c++/1.7for.cpp
    c++/2.1class1.cpp
    c++/2.2class_this.cpp
    c++/2.3class3_explicit.cpp
    DataStructure/10expression.c
    DataStructure/11tree.c
    DataStructure/1pointer.c
    DataStructure/2structure.c
    DataStructure/3typedef.c
    DataStructure/4memory.c
    DataStructure/5Seqlist.c
    DataStructure/6LinkedList.c
    DataStructure/7stack.c
    DataStructure/8queue.c
    DataStructure/9recursion.c
    DataStructure/tempCodeRunnerFile.c)
