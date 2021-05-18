//
// Created by nunoa on 18/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/algorithm/TravelingSalesman.h"
#include "graph/Graph.tpp"

/// TESTS ///

TEST(TravelingSalesman, bruteForce) {
    Graph<int> graph;

    graph.addNode(0, 1, Position(NodeMode::GRID, 2, 0));
    graph.addNode(1, 1, Position(NodeMode::GRID, 1, -1));
    graph.addNode(2, 1, Position(NodeMode::GRID, 0, 3));
    graph.addNode(3, 1, Position(NodeMode::GRID, 5, 2));
    graph.addNode(4, 1, Position(NodeMode::GRID, 1, -3));
    graph.addNode(5, 1, Position(NodeMode::GRID, 0, -3));
    graph.addNode(6, 1, Position(NodeMode::GRID, -3, 0));

    std::vector<Node<int>*> poi = {graph.findNode(1), graph.findNode(2), graph.findNode(3), graph.findNode(4), graph.findNode(5)};

    TravelingSalesman<int>::bruteForce(poi, graph.findNode(0), graph.findNode(6));

}