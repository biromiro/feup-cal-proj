//
// Created by nunoa on 08/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/algorithm/MinimumSpanningTrees.h"

/// TESTS ///

TEST(MinimumSpanningTrees, kruskal) {
    Graph<int> graph;

    graph.addNode(0, 1, Position(NodeMode::GRID, 0, 0));
    graph.addNode(1, 1, Position(NodeMode::GRID, 1, 2));
    graph.addNode(2, 1, Position(NodeMode::GRID, 3, 5));
    graph.addNode(3, 1, Position(NodeMode::GRID, -1, 5));
    graph.addNode(4, 1, Position(NodeMode::GRID, -2, 1));

    graph.addNode(5, 1, Position(NodeMode::GRID, 0,1));

    std::vector<Node<int>*> nodes = {graph.findNode(1), graph.findNode(2), graph.findNode(3), graph.findNode(4)};

    nodes = MinimumSpanningTrees<int>::calculateTreeKruskal(nodes, graph.findNode(0), graph.findNode(5));

    ASSERT_EQ(0, nodes.at(0)->getID());
    ASSERT_EQ(4, nodes.at(1)->getID());
    ASSERT_EQ(1, nodes.at(2)->getID());
    ASSERT_EQ(3, nodes.at(3)->getID());
    ASSERT_EQ(2, nodes.at(4)->getID());
    ASSERT_EQ(5, nodes.at(5)->getID());

}
