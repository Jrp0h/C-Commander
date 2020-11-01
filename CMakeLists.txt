cmake_minimum_required(VERSION 3.5)

project(Arguments)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)
file(GLOB_RECURSE SOURCES "src/*.c" "src/*.h" "main.c")
add_executable(${PROJECT_NAME} ${SOURCES})
