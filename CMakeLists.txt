cmake_minimum_required(VERSION 3.8)

project (dz3)

set(BUILD_TEST ON)

include_directories(include)

add_subdirectory(libs/graphs)
add_subdirectory(libs/Read)

add_executable(dz3
    src/main.cpp
)
target_link_libraries(dz3 read_lib)

if (BUILD_TEST)
    enable_testing()

    add_executable(check tests/test.cpp)
    target_link_libraries(check graphs_lib read_lib -lgtest -lgtest_main -pthread)
    add_test(NAME check COMMAND check)
endif()