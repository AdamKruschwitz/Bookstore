cmake_minimum_required(VERSION 3.8)
project(Bookstore)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Book.cpp UserInterface.cpp Bookstore.cpp BookList.cpp LinkedNode.inl Person.cpp LinkedQueue.inl)
add_executable(Bookstore-2--Electric-Boogaloo ${SOURCE_FILES})