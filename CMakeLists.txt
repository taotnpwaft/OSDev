cmake_policy(SET CMP0048 NEW) 
project(osdev LANGUAGES C ASM VERSION 0.1)
cmake_minimum_required(VERSION 3.24)
set(CMAKE_C_STANDARD 99)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/)