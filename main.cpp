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
#include <src/model/db/userDatabase.h>
#include <model/journeyFinder/journeyFinder.h>

int main(){


    UserDatabase db("resources/database.txt");

    JourneyFinder jf("resources/Penafiel/SCC/penafiel_strong_nodes_latlng.txt",
                     "resources/Penafiel/SCC/penafiel_strong_edges.txt");

    jf.generateJourney(1, 7100, 5, 1000);
    /*srand(time(NULL));

    Graph<struct NodeInfo> g2;


    GraphLoader<NodeInfo> gLoader("resources/Penafiel/SCC/penafiel_strong_nodes_xy.txt",
                                "resources/Penafiel/SCC/penafiel_strong_edges.txt",
                                NodeMode::GRID);

    g2 = gLoader.getGraph();
    std::vector<Edge<NodeInfo>*> vector1, vector2;


    Connectivity<NodeInfo> connect = Connectivity<NodeInfo>(g2);
    std::cout << connect.getNumConnectedComponents();

    vector<Node<NodeInfo> *> parks;

    int destID = 7100, originID = 1;

    GraphManager gv(877, 941,"resources/Penafiel/SCC/penafiel_strong_component.png");

    Pathfinding::dijkstraAdaptation<NodeInfo>(g2, parks, destID, 500);
    if(parks.empty()) return -1;
    std::cout << Pathfinding::getOrderedPath(g2, parks[0]->getID(), destID, vector2);
    gv.buildPath(vector2, GraphViewer::ORANGE);

    if(!Pathfinding::aStarAdaptation(g2, originID, parks[0]->getID())) return -1;
    std::cout << Pathfinding::getOrderedPath(g2, originID, parks[0]->getID(), vector1);
    gv.buildPath(vector1, GraphViewer::BLUE);

    gv.drawPark(parks[0]);
    Node<NodeInfo> * pNode = g2.findNode(destID);
    gv.drawDest(pNode);
    gv.show();
    std::cout << "First path" << std::endl;
    gv.showPath(vector1, TRAVEL);
    std::cout << "Second path" << std::endl;
    gv.showPath(vector2, WALKING);
    gv.finish();*/
    return 0;
}
