cmake_minimum_required(VERSION 3.7)
project(asocjacje)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Csched.cpp Csched.h Cprog.cpp Cprog.h)
add_executable(asocjacje ${SOURCE_FILES})