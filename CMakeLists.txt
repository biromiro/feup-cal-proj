cmake_minimum_required(VERSION 3.19)
project(feup_cal_proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(feup_cal_proj
        main.cpp)
