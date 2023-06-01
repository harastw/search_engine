project(tests)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")
enable_testing()
include_directories(../ ../include ../src)
add_executable(
        ${PROJECT_NAME}
        main.cpp
	../src/InvertedIndex.cpp
	../src/SearchServer.cpp
	../src/ConverterJSON.cpp
)
target_link_libraries(${PROJECT_NAME} gtest gtest_main nlohmann_json::nlohmann_json)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(json)

