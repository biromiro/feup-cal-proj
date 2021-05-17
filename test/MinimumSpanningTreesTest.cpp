//
// Created by nunoa on 08/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/algorithm/MinimumSpanningTrees.h"

/// TESTS ///

TEST(MinimumSpanningTrees, kruskal) {
    UndirectedGraph<int> graph;

    graph.addNode(0, 1, Position(NodeMode::COORDS, 0, 0));
    graph.addNode(1, 1, Position(NodeMode::COORDS, 0, 0));
    graph.addNode(2, 1, Position(NodeMode::COORDS, 0, 0));
    graph.addNode(3, 1, Position(NodeMode::COORDS, 0, 0));
    graph.addNode(4, 1, Position(NodeMode::COORDS, 0, 0));


    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 2, 3);
    graph.addEdge(3, 1, 5);
    graph.addEdge(2, 4, 1);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 4, 6);
    graph.addEdge(0, 4, 3);
    graph.addEdge(2, 3, 3);
    graph.addEdge(0, 3, 2);

    MinimumSpanningTrees<int>::calculateTreeKruskal(graph, 0);

    EXPECT_EQ(4, graph.findNode(2)->getPath()->getOrig()->getID());
    EXPECT_EQ(1, graph.findNode(4)->getPath()->getOrig()->getID());
    EXPECT_EQ(0, graph.findNode(1)->getPath()->getOrig()->getID());
    EXPECT_EQ(nullptr, graph.findNode(0)->getPath());
    EXPECT_EQ(0, graph.findNode(3)->getPath()->getOrig()->getID());
}