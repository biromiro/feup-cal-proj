//
// Created by nrtc on 05/05/2021.
//

#ifndef FEUP_CAL_PROJ_GRAPHLOADER_TPP
#define FEUP_CAL_PROJ_GRAPHLOADER_TPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <utils/graph/Graph.tpp>
#include <utils/algorithm/Distances.h>
#include "NodeMode.h"
#include <direct.h>
#include <windows.h>

template <class T>
class GraphLoader {
public:
    GraphLoader(const std::string& nodes, const std::string& edges, NodeMode mode);
    Graph<T> getGraph();
private:
    std::string nodePath;
    std::string edgePath;
    NodeMode mode;
};

template <class T>
GraphLoader<T>::GraphLoader(const std::string& nodes, const std::string& edges, NodeMode mode) {
    this->nodePath = nodes;
    this->edgePath = edges;
    this->mode = mode;
}

template <class T>
Graph<T> GraphLoader<T>::getGraph() {
    Graph<T> graph;
    std::ifstream nodeFile(nodePath);
    std::ifstream edgeFile(edgePath);
    std::string line;

    if(!nodeFile || !edgeFile) throw std::invalid_argument("Invalid file paths!");

    int nodeNumber, nodeID;
    char sep;
    double x, y;

    nodeFile >> nodeNumber;
    std::getline(nodeFile, line);

    T var;

    for(; nodeNumber > 0; nodeNumber--){
        std::getline(nodeFile, line);
        std::stringstream s(line);
        s >> sep >> nodeID >> sep >> x >> sep >> y >> sep;
        Position pos(mode, x, y);
        graph.addNode(nodeID, var, pos);
    }

    int edgeNumber;
    int node1, node2;

    edgeFile >> edgeNumber;
    std::getline(edgeFile, line);

    for(; edgeNumber > 0; edgeNumber--){
        std::getline(edgeFile, line);
        std::stringstream s(line);
        s >> sep >> node1 >> sep >> node2 >> sep;
        Node<T>* nodeptr1 = graph.findNode(node1);
        Node<T>* nodeptr2 = graph.findNode(node2);
        double cost = Distances::getEuclideanDistance(nodeptr1->getPos(), nodeptr2->getPos());
        graph.addEdge(node1, node2, cost);
    }

    return graph;
}


#endif //FEUP_CAL_PROJ_GRAPHLOADER_TPP
