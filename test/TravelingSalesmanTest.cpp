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

    std::vector<int> shortestPath = TravelingSalesman<int>::bruteForce(poi, graph.findNode(0), graph.findNode(6));

    ASSERT_EQ(0, shortestPath.at(0));
    ASSERT_EQ(3, shortestPath.at(1));
    ASSERT_EQ(2, shortestPath.at(2));
    ASSERT_EQ(1, shortestPath.at(3));
    ASSERT_EQ(4, shortestPath.at(4));
    ASSERT_EQ(5, shortestPath.at(5));
    ASSERT_EQ(6, shortestPath.at(6));

    graph.addNode(7, 1, Position(NodeMode::GRID, 6, 2));

    shortestPath = TravelingSalesman<int>::bruteForce(poi, graph.findNode(0), graph.findNode(7));

    ASSERT_EQ(0, shortestPath.at(0));
    ASSERT_EQ(1, shortestPath.at(1));
    ASSERT_EQ(4, shortestPath.at(2));
    ASSERT_EQ(5, shortestPath.at(3));
    ASSERT_EQ(2, shortestPath.at(4));
    ASSERT_EQ(3, shortestPath.at(5));
    ASSERT_EQ(7, shortestPath.at(6));


    graph.addNode(8, 1, Position(NodeMode::GRID, 0,4));
    graph.addNode(9, 1, Position(NodeMode::GRID, 0,4));

    shortestPath = TravelingSalesman<int>::bruteForce(poi, graph.findNode(8), graph.findNode(9));

//    ASSERT_EQ(8, shortestPath.at(0));
//    ASSERT_EQ(2, shortestPath.at(1));
//    ASSERT_EQ(1, shortestPath.at(2));
//    ASSERT_EQ(5, shortestPath.at(3));
//    ASSERT_EQ(4, shortestPath.at(4));
//    ASSERT_EQ(3, shortestPath.at(5));
//    ASSERT_EQ(9, shortestPath.at(6));
// OR THIS:
//    ASSERT_EQ(8, shortestPath.at(0));
//    ASSERT_EQ(3, shortestPath.at(1));
//    ASSERT_EQ(4, shortestPath.at(2));
//    ASSERT_EQ(5, shortestPath.at(3));
//    ASSERT_EQ(1, shortestPath.at(4));
//    ASSERT_EQ(2, shortestPath.at(5));
//    ASSERT_EQ(9, shortestPath.at(6));

}