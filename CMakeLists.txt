cmake_minimum_required(VERSION 3.17)
project(feup_cal_proj)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    include_directories("$ENV{SFML_PATH}/include")
    link_directories("$ENV{SFML_PATH}/lib")
endif()

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build the Google tests
set(GOOGLETEST_PATH googletest)

add_subdirectory(${GOOGLETEST_PATH})

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)


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
        src/utils/utilitaryStructures/HeuristicNode.h
        src/utils/algorithm/Distances.cpp src/utils/algorithm/Distances.h
        src/utils/algorithm/Pathfinding.cpp src/utils/algorithm/Pathfinding.h
        src/utils/graphLoad/MapData.h
        src/utils/disjointSet/DisjointSet.h
        src/utils/disjointSet/DisjointSetGroup.h src/utils/disjointSet/DisjointSetGroup.cpp
        src/utils/algorithm/MinimumSpanningTrees.h
        src/utils/graph/UndirectedGraph.tpp src/utils/algorithm/MinimumSpanningTrees.tpp src/utils/algorithm/TravelingSalesman.h
        src/utils/graph/UndirectedGraph.tpp src/utils/algorithm/MinimumSpanningTrees.tpp
        src/utils/algorithm/NearestNeighbour.h
        GraphViewerCpp/include/graphviewer.h
        src/utils/graphLoad/GraphManager.h
        src/utils/graphLoad/GraphManager.cpp src/utils/utilitaryStructures/utilFunctions.cpp src/utils/utilitaryStructures/utilFunctions.h)

add_executable(feup_cal_proj main.cpp)

add_executable(feup_cal_proj_tests tests.cpp
        test/DisjointSetTest.cpp test/UndirectedGraphTest.cpp test/MinimumSpanningTreesTest.cpp test/Dijkstra.cpp 
        test/TravelingSalesmanTest.cpp test/NearestNeighbourTest.cpp test/AlgorithmComplexity.cpp)

target_link_libraries(feup_cal_proj cal_lib graphviewer)
target_link_libraries(feup_cal_proj_tests cal_lib gtest_main gmock_main)