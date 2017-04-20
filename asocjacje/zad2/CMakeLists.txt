cmake_minimum_required(VERSION 3.7)
project(zad2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp CWielokat.cpp CWielokat.h CPunkt.cpp CPunkt.h)
add_executable(zad2 ${SOURCE_FILES})