//
// Created by nrtc on 03/05/2021.
//

#include <utils/graphLoad/GraphLoader.tpp>
#include "src/utils/graph/Graph.tpp"
#include <iostream>
#include <algorithm/Connectivity.tpp>
#include <algorithm/Pathfinding.h>

int main(){
    Graph<NodeInfo> g;

    GraphLoader<NodeInfo> gLoader("resources/Espinho/SCC/espinho_strong_nodes_xy.txt",
                                "resources/Espinho/SCC/espinho_strong_edges.txt",
                                NodeMode::GRID);
/*
    GraphLoader<NodeInfo> gLoader("resources/OtherMaps/GridGraphs/4x4/nodes.txt",
                                "resources/OtherMaps/GridGraphs/4x4/edges.txt",
                                NodeMode::GRID);
  */
    // g = gLoader.getGraph();

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
    g.addEdge(5, 4, 2.0);
    g.addEdge(6, 7, 1.0);
    g.addEdge(7, 6, 1.0);
    g.addEdge(4, 6, 1.0);

    Connectivity<NodeInfo> connect = Connectivity<NodeInfo>(g);
    std::cout << connect.getNumConnectedComponents();

    vector<Node<NodeInfo> *> parks;

    Pathfinding::dijkstraAdaptation<NodeInfo>(g, parks, 1, 3);



    return 0;
}
