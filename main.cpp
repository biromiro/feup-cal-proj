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


    Connectivity<NodeInfo> connect = Connectivity<NodeInfo>(g);
    std::cout << connect.getNumConnectedComponents();

    vector<Node<NodeInfo> *> parks;

    Pathfinding::dijkstraAdaptation<NodeInfo>(g, parks, 1, 3);



    return 0;
}
