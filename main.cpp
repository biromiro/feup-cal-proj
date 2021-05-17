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


    GraphLoader<NodeInfo> gLoader("resources/Porto/SCC/porto_strong_nodes_xy.txt",
                                "resources/Porto/SCC/porto_strong_edges.txt",
                                NodeMode::GRID);
    /*GraphLoader<NodeInfo> gLoader("resources/OtherMaps/GridGraphs/16x16/nodes.txt",
                                  "resources/OtherMaps/GridGraphs/16x16/edges.txt",
                                  NodeMode::GRID);*/

    g2 = gLoader.getGraph();
    std::vector<Edge<NodeInfo>*> vector1, vector2;
    // g = gLoader.getGraph();


    Connectivity<NodeInfo> connect = Connectivity<NodeInfo>(g2);
    std::cout << connect.getNumConnectedComponents();

    vector<Node<NodeInfo> *> parks;

    int destID = 27022, originID = 594;

    GraphManager gv(877, 941,"resources/Penafiel/SCC/penafiel_strong_component.png");

    Pathfinding::dijkstraAdaptation<NodeInfo>(g2, parks, destID, 200);
    if(parks.empty()) return -1;
    std::cout << Pathfinding::getOrderedPath(g2, originID, parks[0]->getID(), vector2);

    std::cout << Pathfinding::getOrderedPath(g2, parks[0]->getID(), destID, vector1);

    gv.buildPath(vector1, GraphViewer::BLUE);
    gv.buildPath(vector2, GraphViewer::ORANGE);
    gv.drawPark(parks[0]);
    Node<NodeInfo> * pNode = g2.findNode(destID);
    gv.drawDest(pNode);
    gv.show();
    gv.showPath(vector2, TRAVEL);
    gv.showPath(vector1, WALKING);
    gv.finish();
    return 0;
}
