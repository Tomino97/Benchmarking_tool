cmake_minimum_required(VERSION 3.14)
project(01)

set(CMAKE_CXX_STANDARD 17)

add_executable(list q_list.cpp ubench.hpp) 
add_executable(vect q_vec.cpp ubench.hpp)
