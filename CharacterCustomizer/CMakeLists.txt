cmake_minimum_required(VERSION 3.10)
project(CharacterCustomizer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB SOURCE_FILES "src/*/*.cpp")
list(APPEND SOURCE_FILES "src/main.cpp")

add_executable(CharacterCustomizer ${SOURCE_FILES})

set_target_properties(CharacterCustomizer PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
target_include_directories(CharacterCustomizer PRIVATE src/include)