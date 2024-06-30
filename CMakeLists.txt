cmake_minimum_required(VERSION 3.28)
project(LineCounter)

set(CMAKE_CXX_STANDARD 20)

add_executable(LineCounter main.cpp
        line_counter.cpp
        file_extension.h
        line_counter.h
        SourceCodeData.h
)
