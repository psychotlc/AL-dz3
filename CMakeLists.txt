cmake_minimum_required(VERSION 3.8)

project (dz3)

include_directories(graphs)
add_subdirectory(graphs)

add_executable(dz3
    main.cpp
)
target_link_libraries(dz3 graphs)