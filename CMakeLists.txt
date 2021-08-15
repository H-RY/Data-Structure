cmake_minimum_required(VERSION 3.19)
project(Data-Structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arr SqList/Arr.cpp)
add_executable(LinkList LinkList/Linklist.cpp)
add_executable(Stack stack/Stack.cpp)
add_executable(Queue queue/Queue.cpp)