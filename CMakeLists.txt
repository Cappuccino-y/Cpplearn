cmake_minimum_required(VERSION 3.19)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C_1 try.cpp)
add_executable(C_2 Vector.cpp)
add_executable(C_3 Set.cpp)
add_executable(C_4 Map.cpp)
add_executable(C_5 Stack.cpp)
add_executable(C_6 Queue.cpp)
add_executable(C_7 Others.cpp)

add_executable(leet_code1 lc/lc_bisearch.cpp)
add_executable(lc_remove lc/lc_remove.cpp)
add_executable(lc_sqorder lc/lc_sqorder.cpp)