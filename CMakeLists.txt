cmake_minimum_required(VERSION 3.27)
project(NumberGuesser)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(NumberGuesser
        Headers/Random.h
        src/main.cpp)
