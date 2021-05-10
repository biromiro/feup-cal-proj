//
// Created by nunoa on 08/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/graph/UndirectedGraph.tpp"
#include "src/utils/graph/Node.tpp"

/// TESTS ///

TEST(UndirectedGraph, addEdge) {
    auto graph = UndirectedGraph<int>();

    graph.addNode(0, 1, Position(NodeMode::COORDS, 0,0 ));
    graph.addNode(1, 1, Position(NodeMode::COORDS, 0,0 ));
    graph.addNode(2, 1, Position(NodeMode::COORDS, 0,0 ));

    graph.addEdge(0, 1, 3);

    auto node = graph.findNode(0);
    auto node2 = graph.findNode(1);

    EXPECT_EQ(node->getOutgoing().size(), node2->getOutgoing().size());
    EXPECT_EQ(node->getIncoming().size(), node2->getIncoming().size());
    EXPECT_EQ(node, node->getOutgoing().at(0)->getOrig());
    EXPECT_EQ(node2, node->getOutgoing().at(0)->getDest());
    EXPECT_EQ(node2, node2->getOutgoing().at(0)->getOrig());
    EXPECT_EQ(node, node2->getOutgoing().at(0)->getDest());
    EXPECT_EQ(true, false);
}