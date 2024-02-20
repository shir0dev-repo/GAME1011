cmake_minimum_required(VERSION 3.10)
project(assignment1)

file (GLOB_RECURSE sources src/*.cpp src/header/*.h)

add_executable(assignment1 ${sources})

target_include_directories(assignment1 PUBLIC src/header)