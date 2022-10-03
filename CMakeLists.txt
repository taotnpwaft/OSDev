cmake_policy(SET CMP0048 NEW) 
project(osdev LANGUAGES C ASM VERSION 0.1)
cmake_minimum_required(VERSION 3.24)

set(CMAKE_ASM_COMPILER nasm)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  message(ERROR "This project cannot be built with MSVC. Use CMAKE_C_COMPILER to use an appropriate compiler")
endif()

#add_subdirectory(${PROJECT_SOURCE_DIR}/src/)