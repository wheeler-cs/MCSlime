cmake_minimum_required(VERSION 3.25.1)
project(MCSlime)

string(TIMESTAMP CURRENT_DATE "%Y-%m-%d")
add_compile_definitions(PROGRAM_VERSION="${CURRENT_DATE}")


include_directories(${CMAKE_SOURCE_DIR}/inc)
file(GLOB SOURCES "src/*c")

add_executable(MCSlime ${SOURCES})