//
// Created by nrtc on 16/05/2021.
//

#include "GraphManager.h"

GraphManager::GraphManager(int height, int width, std::string path): imgHeight(height), imgWidth(width), imagePath(path) {
    this->gv.setCenter(sf::Vector2f(height/2, width/2));
    this->gv.setBackground("resources/Espinho/SCC/espinho_strong_component.png");
}

void GraphManager::buildPath(const vector<Edge<struct NodeInfo> *> &edges) {
    if(edges.empty()) return;
    Node<struct NodeInfo>* origin = edges.at(0)->getOrig();
    GraphViewer::Node* orig, * dest;
    try{
        orig = &gv.addNode(origin->getID(), sf::Vector2f(origin->getPos().getX(), origin->getPos().getY()));
    } catch (std::invalid_argument &e) {
        orig = &gv.getNode(origin->getID());
    }
    orig->setColor(GraphViewer::WHITE);
    size_t numEdges = gv.getEdges().size();
    for(Edge<struct NodeInfo>* edge: edges){
        orig = &gv.getNode(edge->getOrig()->getID());
        try{
            dest = &gv.addNode(edge->getDest()->getID(), sf::Vector2f(edge->getDest()->getPos().getX(), edge->getDest()->getPos().getY()));
        } catch (std::invalid_argument &e) {
            dest = &gv.getNode(edge->getDest()->getID());
        }
        try{
            gv.addEdge(numEdges++, *orig, *dest, GraphViewer::Edge::EdgeType::DIRECTED);
        } catch (std::invalid_argument &e) {}
        dest->setColor(GraphViewer::YELLOW);
    }
}

void GraphManager::show() {
    this->gv.createWindow(imgHeight,imgWidth);
    this->gv.join();
}

