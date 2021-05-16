//
// Created by nrtc on 03/05/2021.
//

#include <utils/graphLoad/GraphLoader.tpp>
#include "src/utils/graph/Graph.tpp"
#include <iostream>
#include <algorithm/Connectivity.tpp>
#include <algorithm/Pathfinding.h>
#include <graphviewer.h>
#include <graphLoad/GraphManager.h>

int main(){
    Graph<struct NodeInfo> g2;

    GraphLoader<NodeInfo> gLoader("resources/Espinho/SCC/espinho_strong_nodes_xy.txt",
                                "resources/Espinho/SCC/espinho_strong_edges.txt",
                                NodeMode::GRID);
/*
    GraphLoader<NodeInfo> gLoader("resources/OtherMaps/GridGraphs/4x4/nodes.txt",
                                "resources/OtherMaps/GridGraphs/4x4/edges.txt",
                                NodeMode::GRID);

    /*g.addNode(1, " ", Position(NodeMode::GRID, 1, 1));
    g.addNode(2, " ", Position(NodeMode::GRID, 2, 2));
    g.addNode(3, " ", Position(NodeMode::GRID, 3, 3));
    g.addNode(4, " ", Position(NodeMode::GRID, 4, 4));
    g.addNode(5, " ", Position(NodeMode::GRID, 5, 5));
    g.addNode(6, " ", Position(NodeMode::GRID, 6, 6));
    g.addNode(7, " ", Position(NodeMode::GRID, 7, 7));


    g.addEdge(1,3,1.0);
    g.addEdge(3,2,2.0);
    g.addEdge(2,1,1.0);
    g.addEdge(4,4,1.0);
    g.addEdge(3, 5, 1.0);
    g.addEdge(5, 4, 2.0);
    g.addEdge(6, 7, 1.0);
    g.addEdge(7, 6, 1.0);*/
/*
    Connectivity<string> connect = Connectivity<std::string>(g1);
    std::cout << connect.getNumConnectedComponents() << std::endl;*/

    g2 = gLoader.getGraph();
    std::vector<Edge<NodeInfo>*> vector1, vector2;
    // g = gLoader.getGraph();


    Connectivity<NodeInfo> connect = Connectivity<NodeInfo>(g2);
    std::cout << connect.getNumConnectedComponents();

    vector<Node<NodeInfo> *> parks;

    Pathfinding::dijkstraAdaptation<NodeInfo>(g2, parks, 10121, 3000);
    if(parks.empty()) return -1;
    std::cout << Pathfinding::getOrderedPath(g2, 3617, parks[0]->getID(), vector1);
    std::cout << Pathfinding::getOrderedPath(g2, parks[0]->getID(),10121, vector2);

    GraphManager gv(877, 941,"resources/Espinho/SCC/espinho_strong_component.png");
    gv.buildPath(vector1);
    gv.buildPath(vector2);
    gv.show();
    return 0;
}
