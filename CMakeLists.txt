cmake_minimum_required(VERSION 3.8)
project(search-engine)
include(FetchContent)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.10.5
        )
FetchContent_MakeAvailable(json)
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_executable(search-engine search-engine.cpp)
target_link_libraries(search-engine nlohmann_json::nlohmann_json)
Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)
add_executable(tests test.cpp)
target_link_libraries(tests Catch2::Catch2WithMain
			    nlohmann_json::nlohmann_json)
