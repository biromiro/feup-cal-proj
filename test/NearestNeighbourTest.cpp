//
// Created by nunoa on 17/05/21.
//

#include <gtest/gtest.h>
#include <graphLoad/NodeMode.h>
#include "src/utils/algorithm/NearestNeighbour.h"
#include "graph/Graph.tpp"

/// TESTS ///

TEST(NearestNeigbour, nb) {
    Graph<int> graph;

    graph.addNode(0, 1, Position(NodeMode::GRID, 5, 0));
    graph.addNode(1, 1, Position(NodeMode::GRID, 2, 0));
    graph.addNode(2, 1, Position(NodeMode::GRID, 3, 1));
    graph.addNode(3, 1, Position(NodeMode::GRID, 3, 3));
    graph.addNode(4, 1, Position(NodeMode::GRID, 4, 1));
    graph.addNode(5, 1, Position(NodeMode::GRID, 4, 1));

    std::vector<Node<int>*> poi;

    poi.push_back(graph.findNode(0));
    poi.push_back(graph.findNode(2));
    poi.push_back(graph.findNode(3));
    poi.push_back(graph.findNode(4));

    std::vector<int> tour = NearestNeighbour<int>::getTour(poi, graph.findNode(1), graph.findNode(5));

    ASSERT_EQ(1, tour.at(0));
    ASSERT_EQ(2, tour.at(1));
    ASSERT_EQ(4, tour.at(2));
    ASSERT_EQ(0, tour.at(3));
    ASSERT_EQ(3, tour.at(4));
    ASSERT_EQ(5, tour.at(5));
}
