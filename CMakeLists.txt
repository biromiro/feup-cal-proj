cmake_minimum_required(VERSION 3.17)
project(feup_cal_proj)

set(CMAKE_CXX_STANDARD 17)

# Build the Google tests
set(GOOGLETEST_PATH googletest)
add_subdirectory(${GOOGLETEST_PATH})

# set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(.)
include_directories(src)
include_directories(src/utils)

file(COPY resources DESTINATION .)

add_library(cal_lib
        src/utils/algorithm/Connectivity.tpp
        src/utils/graph/Node.tpp
        src/utils/graph/Edge.tpp
        src/utils/graph/Graph.tpp
        src/utils/graph/MutablePriorityQueue.tpp
        src/utils/graphLoad/GraphLoader.tpp
        src/utils/graph/Position.cpp src/utils/graph/Position.h
        src/utils/graphLoad/NodeMode.h
        src/utils/algorithm/Distances.cpp src/utils/algorithm/Distances.h
        src/utils/algorithm/Pathfinding.cpp src/utils/algorithm/Pathfinding.h
        src/utils/disjointSet/SetType.h
        src/utils/disjointSet/DisjointSet.h
        src/utils/algorithm/MinimumSpanningTrees.h
        src/utils/disjointSet/DisjointSet.tpp src/utils/graph/UndirectedGraph.tpp)

add_executable(feup_cal_proj main.cpp)

add_executable(feup_cal_proj_tests tests.cpp
        test/DisjointSetTest.cpp test/UndirectedGraphTest.cpp)

target_link_libraries(feup_cal_proj cal_lib)
target_link_libraries(feup_cal_proj_tests cal_lib gtest_main gmock_main)