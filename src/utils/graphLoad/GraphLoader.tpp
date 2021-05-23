//
// Created by nrtc on 05/05/2021.
//

#ifndef FEUP_CAL_PROJ_GRAPHLOADER_TPP
#define FEUP_CAL_PROJ_GRAPHLOADER_TPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <utils/graph/Graph.tpp>
#include <utils/algorithm/Distances.h>
#include <exception/incompatibleNodeToEdgeFile/incompatibleNodeToEdgeFile.h>
#include "NodeMode.h"
#include "MapData.h"

template <class T>
class GraphLoader {
public:
    GraphLoader();
    GraphLoader(const std::string& nodes, const std::string& edges, NodeMode mode, const std::string& parks = "");
    Graph<T> getGraph();
private:
    std::string nodePath;
    std::string edgePath;
    std::string parksPath;
    NodeMode mode;
    Graph<T> graph;
    bool randomParkingMode = false;
    NodeInfo genRandomPark();
    void setRandomParkingMode();
    void genGraph();
};

template <class T>
GraphLoader<T>::GraphLoader(const std::string& nodes, const std::string& edges, NodeMode mode, const std::string& parks) {
    this->nodePath = nodes;
    this->edgePath = edges;
    this->mode = mode;
    this->parksPath = parks;
    if(parks == "") setRandomParkingMode();
    genGraph();
}

template <class T>
void GraphLoader<T>::genGraph() {
    if(this->randomParkingMode) srand((int)time(0));

    Graph<T> graph;
    std::ifstream nodeFile(nodePath);
    std::ifstream edgeFile(edgePath);
    std::string line;

    if(!nodeFile || !edgeFile) throw std::invalid_argument("Invalid file paths!");

    int nodeNumber, nodeNumberCopy, nodeID;
    char sep;
    double x, y;

    nodeFile >> nodeNumber;
    nodeNumberCopy = nodeNumber;
    std::getline(nodeFile, line);

    for(; nodeNumber > 0; nodeNumber--){
        std::getline(nodeFile, line);
        std::stringstream s(line);
        s >> sep >> nodeID >> sep >> x >> sep >> y >> sep;
        Position pos(mode, x, y);

        NodeInfo nodeInfo = this->randomParkingMode && ((rand() % 10 + 1) == 1)
                    ? genRandomPark() : NodeInfo();

        if constexpr (std::is_same<T, NodeInfo>::value)
            graph.addNode(nodeID, nodeInfo, pos);
        else
            graph.addNode(nodeID, T(), pos);

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
        if(nodeptr1 == nullptr || nodeptr2 == nullptr) throw IncompatibleNodeToEdgeFile(nodePath, edgePath, "The provided files are not compatible!");
        double cost = Distances::getEuclideanDistance(nodeptr1->getPos(), nodeptr2->getPos());
        graph.addEdge(node1, node2, cost);
    }

    if(!this->randomParkingMode) {
        // Todo , read from file parking lots and info
    }

    this->graph = graph;
}

template<class T>
void GraphLoader<T>::setRandomParkingMode() {
    this->randomParkingMode = true;
}

template<class T>
NodeInfo GraphLoader<T>::genRandomPark() {
    int maxCap = rand() % 40 +1;
    int currCap = rand() % maxCap + 1;

    NodeInfo info(maxCap, currCap,
                  [](int x, int y, int z) {
                      double priceFactor = (rand() % 10) / 100; // Euro per minute [0, 10] cents
                      double capPrice = (rand() % 10) / 100; // Extra Euro per capacity percentage [0, 10] cents

                      return priceFactor*x + capPrice*y/z;
                  });
    return info;

}

template<class T>
Graph<T> GraphLoader<T>::getGraph() {
    return graph;
}

template<class T>
GraphLoader<T>::GraphLoader() = default;


#endif //FEUP_CAL_PROJ_GRAPHLOADER_TPP
