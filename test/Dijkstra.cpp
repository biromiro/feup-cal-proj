//
// Created by andremoreira9 on 5/10/21.
//
#include <gtest/gtest.h>
#include <graphLoad/MapData.h>
#include <graph/Graph.tpp>
#include <algorithm/Pathfinding.h>
#include "src/utils/disjointSet/DisjointSetGroup.h"
#include "src/utils/graph/Node.tpp"

void setup(Graph<NodeInfo> &g) {
    g.addNode(1, NodeInfo(), Position(NodeMode::GRID, 1, 1));
    g.addNode(2, NodeInfo(2, 1,
                          [](int x, int y, int z) {
                              double priceFactor = (rand() % 10) / 100; // Euro per minute [0, 10] cents
                              double capPrice = (rand() % 10) / 100; // Extra Euro per capacity percentage [0, 10] cents

                              return priceFactor*x + capPrice*y/z;
                          }), Position(NodeMode::GRID, 2, 2));
    g.addNode(3, NodeInfo(), Position(NodeMode::GRID, 3, 3));
    g.addNode(4,     NodeInfo(5, 5,
                              [](int x, int y, int z) {
                                  double priceFactor = (rand() % 10) / 100; // Euro per minute [0, 10] cents
                                  double capPrice = (rand() % 10) / 100; // Extra Euro per capacity percentage [0, 10] cents

                                  return priceFactor*x + capPrice*y/z;
                              }), Position(NodeMode::GRID, 4, 4));
    g.addNode(5, NodeInfo(), Position(NodeMode::GRID, 5, 5));
    g.addNode(6, NodeInfo(), Position(NodeMode::GRID, 6, 6));
    g.addNode(7, NodeInfo(5, 2,
                          [](int x, int y, int z) {
                              double priceFactor = (rand() % 10) / 100; // Euro per minute [0, 10] cents
                              double capPrice = (rand() % 10) / 100; // Extra Euro per capacity percentage [0, 10] cents

                              return priceFactor*x + capPrice*y/z;
                          }), Position(NodeMode::GRID, 7, 7));


    g.addEdge(1,3,1.0);
    g.addEdge(3,2,2.0);
    g.addEdge(2,1,1.0);
    g.addEdge(4,4,1.0);
    g.addEdge(3, 5, 1.0);
    g.addEdge(3, 7, 3.0);
    g.addEdge(5, 4, 2.0);
    g.addEdge(6, 7, 1.0);
    g.addEdge(7, 6, 1.0);
    g.addEdge(4, 6, 1.0);

}

TEST(Dijkstra, load){
    Graph<NodeInfo> g;
    setup(g);
    ASSERT_EQ(7, g.getNodeSet().size());
}

TEST(Dijkstra, checkPath) {
    Graph<NodeInfo> g;
    setup(g);

    vector<Node<NodeInfo> *> parks;

    Pathfinding::dijkstraAdaptation<NodeInfo>(g, parks, 1, std::numeric_limits<int>::max());

    double distances[] = {0, 3, 1, 4, 2, 5, 4};
    int path[] = {-1, 3, 1, 5, 3, 7, 3};

    int i = 0;
    for (auto n : g.getNodeSet()) {
        std::cout << i << std::endl;
        ASSERT_EQ(distances[i], n.second->getDist());
        int pathIdx = path[i];
        if (i == 0) {
            ASSERT_EQ(nullptr, g.getNodeSet().at(0)->getPath());
        }
        else {
            int expected = path[i];
            int got = n.second->getPath()->getID();

            ASSERT_EQ(expected, got);
        }
        i++;
    }
}

TEST(Dijkstra, checkParksMaxRadius) {
    Graph<NodeInfo> g;
    setup(g);

    vector<Node<NodeInfo> *> parks;

    Pathfinding::dijkstraAdaptation<NodeInfo>(g, parks, 1, std::numeric_limits<int>::max());

    ASSERT_EQ(2, parks.size());
    ASSERT_EQ(2, parks.at(0)->getID());
    ASSERT_EQ(7, parks.at(1)->getID());
}

TEST(Dijkstra, checkParkRadius) {
    Graph<NodeInfo> g;
    setup(g);

    vector<Node<NodeInfo> *> parks;

    Pathfinding::dijkstraAdaptation<NodeInfo>(g, parks, 1, 3);

    ASSERT_EQ(1, parks.size());
    ASSERT_EQ(2, parks.at(0)->getID());
}
