project(tests)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")
enable_testing()
include_directories(../ ../include)
add_executable(
        ${PROJECT_NAME}
        InverterIndexTest.cpp
        SearchServerTest.cpp
	../src/InvertedIndex.cpp
	../src/SearchServer.cpp
)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

