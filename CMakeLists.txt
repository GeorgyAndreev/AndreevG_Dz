cmake_minimum_required(VERSION 3.13)
project(AndreevG_Dz)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(AndreevG_Dz
        main.cpp
        header.h
        encryption.cpp
        decryption.cpp
        source.cpp)