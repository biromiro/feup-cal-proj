//
// Created by nunoa on 07/05/21.
//

#include <gtest/gtest.h>
#include "src/utils/disjointSet/SetType.h"
#include "src/utils/disjointSet/DisjointSet.h"
#include "src/utils/graph/Node.tpp"

/// TESTS ///

TEST(DisjointSet, SetType) {
    auto type = SetType(1);

    EXPECT_EQ(0, type.getRank());
    EXPECT_EQ((const SetType*) &type, type.getPath());
    EXPECT_EQ(1, type.getId());
}

TEST(DisjointSet, DisjointSet) {
    int node = 0;
    int node2 = 1;
    int node3 = 2;
    int node4 = 3;

    std::vector<int> nodes;
    nodes.push_back(node);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    std::vector<SetType*> sets;

    DisjointSet nodeSet = DisjointSet();

    for(int pNode : nodes) {
        sets.push_back(nodeSet.createSet(pNode));
        EXPECT_EQ(typeid(SetType*), typeid(sets.back()));
        EXPECT_EQ(0, sets.back()->getRank());
        EXPECT_EQ(sets.back(), sets.back()->getPath());
        EXPECT_EQ(pNode, sets.back()->getId());
    }

    EXPECT_EQ(sets.back(), nodeSet.findSet(nodes.back()));
    nodeSet.linkSets(sets.back(), sets.front());
    EXPECT_EQ(sets.front(), nodeSet.findSet(nodes.back()));
    EXPECT_EQ(sets.front(), nodeSet.findSet(nodes.front()));
    nodeSet.linkSets(sets.at(1), sets.front());
    nodeSet.linkSets(sets.at(2), sets.front());
    EXPECT_EQ(sets.front(), nodeSet.findSet(nodes.at(1)));
    EXPECT_EQ(sets.front(), nodeSet.findSet(nodes.at(2)));
}
