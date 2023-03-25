cmake_minimum_required(VERSION 3.8)

project (WriteAndRead)
include_directories(../../include)
add_library(WriteAndRead STATIC 
            write.cpp 
            read.cpp
)
target_link_libraries(WriteAndRead graphs)