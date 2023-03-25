cmake_minimum_required(VERSION 3.8)

project (dz3)

include_directories(include)

add_subdirectory(libs/graphs)
add_subdirectory(libs/Read)

add_executable(dz3
    app/main.cpp
)
target_link_libraries(dz3 graphs Read)