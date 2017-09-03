cmake_minimum_required(VERSION 3.8)
project(mqclient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
include_directories(/opt/mqm/inc)
include_directories(/usr/local/lib)
add_executable(mqclient ${SOURCE_FILES})