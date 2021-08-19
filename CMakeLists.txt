cmake_minimum_required(VERSION 3.19)
project(Data-Structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(array_list SqList/array_list.cpp)
add_executable(link_list LinkList/link_list.cpp)
add_executable(link_stack Stack/link_stack.cpp)
add_executable(stack Stack/stack.cpp)
add_executable(queue Queue/queue.cpp)
add_executable(link_queue Queue/link_queue.cpp)
add_executable(link_binary_tree Tree/link_binary_tree.cpp)