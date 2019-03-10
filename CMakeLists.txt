cmake_minimum_required(VERSION 3.13)
project(car)

set(CMAKE_CXX_STANDARD 14)

add_executable(car main.cpp)

target_link_libraries(car -lglut -lGL -lGLU)