cmake_minimum_required(VERSION 3.7)
project(zad2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Csched.cpp Csched.h Cprog.cpp Cprog.h Cbase.cpp Cbase.h Cprog2.cpp Cprog2.h)
add_executable(zad2 ${SOURCE_FILES})