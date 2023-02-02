cmake_minimum_required(VERSION 3.8)

include(FetchContent)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.10.5
        )
FetchContent_MakeAvailable(json)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_executable(search-engine search-engine.cpp)

target_link_libraries(search-engine PRIVATE nlohmann_json::nlohmann_json)
