//
// Created by nunoa on 08/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/graph/UndirectedGraph.tpp"
#include "src/utils/graph/Node.tpp"

/// TESTS ///

TEST(UndirectedGraph, addEdge) {
    auto graph = UndirectedGraph<int>({});

    graph.addNode(0, 1, Position(NodeMode::GRID, 0,0 ));
    graph.addNode(1, 1, Position(NodeMode::GRID, 0,0 ));
    graph.addNode(2, 1, Position(NodeMode::GRID, 0,0 ));

    graph.addEdge(0, 1, 3);

    auto node = graph.findNode(0);
    auto node2 = graph.findNode(1);

    EXPECT_EQ(node->getOutgoing().size(), node2->getOutgoing().size());
    EXPECT_EQ(node->getIncoming().size(), node2->getIncoming().size());
    EXPECT_EQ(node, node->getOutgoing().at(0)->getOrig());
    EXPECT_EQ(node2, node->getOutgoing().at(0)->getDest());
    EXPECT_EQ(node2, node2->getOutgoing().at(0)->getOrig());
    EXPECT_EQ(node, node2->getOutgoing().at(0)->getDest());
}

TEST(UndirectedGraph, constructor) {
    Graph<int> graph;
    bool found;

    graph.addNode(0, 1, Position(NodeMode::GRID, 0,0 ));
    graph.addNode(1, 1, Position(NodeMode::GRID, 1,-3 ));
    graph.addNode(2, 1, Position(NodeMode::GRID, 0,5 ));
    graph.addNode(3, 1, Position(NodeMode::GRID, -1,5 ));

    std::vector<Node<int>*> nodes = graph.getNodeSet();

    UndirectedGraph<int> uGraph = UndirectedGraph<int>(nodes);

    nodes = uGraph.getNodeSet();

    for(size_t i = 0; i < nodes.size(); i++) {
        Node<int> *firstNode = nodes.at(i);

        for(size_t j = 0; j < nodes.size(); j++) {
            if(j == i) continue;
            Node<int> *secondNode = nodes.at(j);
            found = false;

            for(auto edge : firstNode->getOutgoing()) {
                if(edge->getDest() == secondNode) {
                    ASSERT_EQ(Distances::getEuclideanDistance(firstNode->getPos(), secondNode->getPos()), edge->getCost());
                    found = true;
                    break;
                }
            }
            if(!found) ASSERT_EQ(false, true);

            found = false;

            for(auto edge : firstNode->getIncoming()) {
                if(edge->getOrig() == secondNode) {
                    ASSERT_EQ(Distances::getEuclideanDistance(firstNode->getPos(), secondNode->getPos()), edge->getCost());
                    found = true;
                    break;
                }
            }

            if(!found) ASSERT_EQ(false, true);
        }
    }
}
