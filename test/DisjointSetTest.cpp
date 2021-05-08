//
// Created by nunoa on 07/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/disjointSet/SetType.h"
#include "src/utils/disjointSet/DisjointSet.h"
#include "src/utils/graph/Node.tpp"

/// TESTS ///

TEST(DisjointSet, SetType) {
    auto* node = new Node(0, 0, Position(NodeMode::COORDS,0,0));
    auto type = SetType<Node<int>*>(node);

    EXPECT_EQ(0, type.getRank());
    EXPECT_EQ((const SetType<Node<int>*>*) &type, type.getPath());
    EXPECT_EQ(node, type.getValue());

    delete node;
}

TEST(DisjointSet, DisjointSet) {
    auto* node = new Node(0, 0, Position(NodeMode::COORDS,0,0));
    auto* node2 = new Node(1, 0, Position(NodeMode::COORDS,1,0));
    auto* node3 = new Node(2, 0, Position(NodeMode::COORDS,2,0));
    auto* node4 = new Node(3, 0, Position(NodeMode::COORDS,2,0));

    std::vector<Node<int>*> nodes;
    nodes.push_back(node);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    std::vector<SetType<Node<int>*>*> sets;

    DisjointSet<Node<int>*> nodeSet = DisjointSet<Node<int>*>();

    for(Node<int>* pNode : nodes) {
        sets.push_back(nodeSet.createSet(pNode));
        EXPECT_EQ(typeid(SetType<Node<int>*>*), typeid(sets.back()));
        EXPECT_EQ(0, sets.back()->getRank());
        EXPECT_EQ(sets.back(), sets.back()->getPath());
        EXPECT_EQ(pNode, sets.back()->getValue());
    }

    EXPECT_EQ(sets.back(), nodeSet.findSet(sets.back()));
    nodeSet.linkSets(sets.back(), sets.front());
    EXPECT_EQ(sets.front(), nodeSet.findSet(sets.back()));
    EXPECT_EQ(sets.front(), nodeSet.findSet(sets.front()));
    nodeSet.linkSets(sets.at(1), sets.front());
    nodeSet.linkSets(sets.at(2), sets.front());
    EXPECT_EQ(sets.front(), nodeSet.findSet(sets.at(1)));
    EXPECT_EQ(sets.front(), nodeSet.findSet(sets.at(2)));
}
