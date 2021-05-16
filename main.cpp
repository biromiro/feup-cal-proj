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
    srand(time(NULL));

    Graph<struct NodeInfo> g2;

    GraphLoader<NodeInfo> gLoader("resources/Penafiel/SCC/penafiel_strong_nodes_xy.txt",
                                "resources/Penafiel/SCC/penafiel_strong_edges.txt",
                                NodeMode::GRID);

    g2 = gLoader.getGraph();
    std::vector<Edge<NodeInfo>*> vector1, vector2;
    // g = gLoader.getGraph();


    Connectivity<NodeInfo> connect = Connectivity<NodeInfo>(g2);
    std::cout << connect.getNumConnectedComponents();

    vector<Node<NodeInfo> *> parks;

    int destId = 2000;

    GraphManager gv(877, 941,"resources/Espinho/SCC/penafiel_strong_component.png");

    Pathfinding::dijkstraAdaptation<NodeInfo>(g2, parks, destId, 1000);
    if(parks.empty()) return -1;
    std::cout << Pathfinding::getOrderedPath(g2, parks[0]->getID(), destId, vector2);

    Pathfinding::aStarAdaptation(g2, 1000, parks[0]->getID());
    std::cout << Pathfinding::getOrderedPath(g2, parks[0]->getID(), 3617, vector1);

    gv.buildPath(vector1, GraphViewer::BLUE);
    gv.buildPath(vector2, GraphViewer::ORANGE);
    gv.drawPark(parks[0]);
    Node<NodeInfo> * pNode = g2.findNode(destId);
    gv.drawDest(pNode);
    gv.show();
    return 0;
}
