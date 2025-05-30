cmake_minimum_required(VERSION 3.10)
project(ChessEngineSFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(chess_engine ${SOURCES} main.cpp)

target_link_libraries(chess_engine sfml-graphics sfml-window sfml-system)