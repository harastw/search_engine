project(search-engine)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

include_directories("../include/" "./")

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)

FetchContent_MakeAvailable(json)

add_executable(search-engine main.cpp
			     ConverterJSON.cpp
			     InvertedIndex.cpp
			     SearchServer.cpp)
target_link_libraries(search-engine PRIVATE nlohmann_json::nlohmann_json)
