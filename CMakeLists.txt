# Project
cmake_minimum_required(VERSION 3.10)
project(cpw_calc VERSION 1.0)

configure_file(cpw_calcConfig.h.in cpw_calcConfig.h)

# C++ Standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Compiler
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall --std=c11")

# Adding directories

set(HEADER ${CMAKE_SOURCE_DIR}/include)
include_directories(include)
add_subdirectory(src)

