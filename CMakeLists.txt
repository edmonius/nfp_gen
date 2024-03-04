cmake_minimum_required(VERSION 3.9)
project(NFP_Generator)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

include_directories(src)

file(GLOB_RECURSE ALL_SOURCES_FILES
    src/*.cpp
)

configure_file(configs/pieces_plg.json pieces_plg.json COPYONLY)
configure_file(configs/pieces_plg.dat pieces_plg.dat COPYONLY)
configure_file(configs/board.dat board.dat COPYONLY)

add_executable(NFP_Generator
src/main.cpp
${ALL_SOURCES_FILES}
)
target_include_directories(NFP_Generator PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(NFP_Generator PRIVATE nlohmann_json::nlohmann_json)
