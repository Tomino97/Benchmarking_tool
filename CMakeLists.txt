cmake_minimum_required(VERSION 3.14)
project(01)

set(CMAKE_CXX_STANDARD 17)

add_executable(list src/q_list.cpp src/ubench.hpp) 
add_executable(vect src/q_vec.cpp src/ubench.hpp)
