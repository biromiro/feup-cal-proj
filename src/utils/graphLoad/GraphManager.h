//
// Created by nrtc on 16/05/2021.
//

#ifndef FEUP_CAL_PROJ_GRAPHMANAGER_H
#define FEUP_CAL_PROJ_GRAPHMANAGER_H

#include "graphviewer.h"
#include "src/utils/graph/Graph.tpp"

class GraphManager{
public:
    GraphManager(int height, int width, std::string path);
    void buildPath(const std::vector<Edge<struct NodeInfo>*>& edges, GraphViewer::Color color);
    void show();

    void drawPark(Node<NodeInfo> *&pNode);
    void finish();
    void drawDest(Node<struct NodeInfo> *i);
    void showPath(const vector<Edge<NodeInfo> *> &edges, TravelType type);

private:
    GraphViewer gv;
    int imgHeight, imgWidth;
    std::string imagePath;
    std::map<Edge<NodeInfo>*, id_t> edgeIDs;
};

#endif //FEUP_CAL_PROJ_GRAPHMANAGER_H
