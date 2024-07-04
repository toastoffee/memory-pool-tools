cmake_minimum_required(VERSION 3.27)
project(memory_pool_tools)

set(CMAKE_CXX_STANDARD 11)

add_executable(memory_pool_tools
        main.cpp
        memory_pool.hpp)
