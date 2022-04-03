cmake_minimum_required(VERSION 3.21)
project(CPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP Tests/Test2.cpp)

add_executable(Class1 Class1/Class1.cpp)
add_executable(Class2 Class2/Class2.cpp)
add_executable(Class3 Class3/Task1.cpp)
add_executable(Task1 Class3/Task1.cpp)
add_executable(Task2 Class3/Task2.cpp)
add_executable(Task3 Class3/Task3.cpp)