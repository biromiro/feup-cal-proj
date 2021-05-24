//
// Created by nunoa on 07/05/21.
//

#include "algorithm/Connectivity.tpp"
#include "graphLoad/GraphLoader.tpp"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    Graph<string> g;

    GraphLoader<string> gLoader("resources/OtherMaps/GridGraphs/4x4/nodes.txt",
                                "resources/OtherMaps/GridGraphs/4x4/edges.txt",
                                NodeMode::GRID);
    g = gLoader.getGraph();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
