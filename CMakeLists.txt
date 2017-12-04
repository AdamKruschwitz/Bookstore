cmake_minimum_required(VERSION 3.8)
project(Bookstore)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Book.cpp ArrayList.inl LinkedNode.inl ArrayMap.inl LinkedNode.inl LinkedQueue.inl UserInterface.cpp UserInterface.h Person.cpp)
add_executable(Bookstore-2--Electric-Boogaloo ${SOURCE_FILES})