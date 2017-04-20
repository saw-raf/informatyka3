cmake_minimum_required(VERSION 3.7)
project(polimorfiz)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp CInstrument.cpp CInstrument.h CTrabka.cpp CTrabka.h CGitara.cpp CGitara.h)
add_executable(polimorfiz ${SOURCE_FILES})