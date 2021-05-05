cmake_minimum_required(VERSION 3.19)
project(feup_cal_proj)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(src)
include_directories(src/utils)

add_executable(feup_cal_proj
        main.cpp
        src/utils/algorithm/Connectivity.tpp
        src/utils/graph/Node.tpp
        src/utils/graph/Edge.tpp
        src/utils/graph/Graph.tpp
        src/utils/graph/MutablePriorityQueue.tpp
        src/utils/graphLoad/GraphLoader.tpp src/utils/graph/Position.cpp
        src/utils/graph/Position.h
        src/utils/graphLoad/NodeMode.h
        src/utils/algorithm/Distances.cpp
        src/utils/algorithm/Distances.h)
