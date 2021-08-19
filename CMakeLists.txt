cmake_minimum_required(VERSION 3.19)
project(Data-Structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arr SqList/Arr.cpp)
add_executable(LinkList LinkList/Linklist.cpp)
add_executable(LinkStack stack/LinkStack.cpp)
add_executable(Stack stack/stack.cpp)
add_executable(Queue queue/Queue.cpp)
add_executable(LinkQueue queue/LinkQueue.cpp)
add_executable(LinkBinaryTree tree/LinkBinaryTree.cpp)