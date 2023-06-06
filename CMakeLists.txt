project(search-engine-root)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")

add_subdirectory(src)
add_subdirectory(Google_tests)
