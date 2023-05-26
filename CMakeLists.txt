cmake_minimum_required(VERSION 3.8)

project (dz3)

set(BUILD_TEST OFF)

include_directories(include)

add_subdirectory(libs/graphs)
add_subdirectory(libs/Read)

add_executable(dz3
    src/main.cpp
)
target_link_libraries(dz3 read_lib)
