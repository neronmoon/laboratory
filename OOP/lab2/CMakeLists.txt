cmake_minimum_required(VERSION 3.6)
project(lab2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp country.cpp country.h group.cpp group.h)
add_executable(lab2 ${SOURCE_FILES})