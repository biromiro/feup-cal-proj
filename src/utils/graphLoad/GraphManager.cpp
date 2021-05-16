//
// Created by nrtc on 16/05/2021.
//

#include "GraphManager.h"

GraphManager::GraphManager(int height, int width, std::string path): imgHeight(height), imgWidth(width), imagePath(path) {
    // this->gv.setCenter(sf::Vector2f(height/2, width/2));
    this->gv.setBackground("resources/Espinho/SCC/espinho_strong_component.png", sf::Vector2f(-height/2, -width/2));
    this->gv.setScale(10);
}

void GraphManager::buildPath(const vector<Edge<struct NodeInfo> *> &edges, GraphViewer::Color color) {
    if(edges.empty()) return;
    Node<struct NodeInfo>* origin = edges.at(0)->getOrig();
    GraphViewer::Node* orig, * dest;
    int factor = 20;
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
            GraphViewer::Edge gvedge = gv.addEdge(numEdges++, *orig, *dest, GraphViewer::Edge::EdgeType::DIRECTED);
            // gvedge.setColor(color);
        } catch (std::invalid_argument &e) {}
        dest->setColor(color);
        dest->setSize(10);
    }
}

void GraphManager::show() {
    GraphViewer::Node node = gv.addNode(0, sf::Vector2f(1402, 10));
    node.setColor(GraphViewer::ORANGE);
    node.setSize(50);
    this->gv.createWindow(imgHeight,imgWidth);
    this->gv.join();
}

void GraphManager::drawPark(Node<NodeInfo> *&pNode) {
    GraphViewer::Node* node;
    int factor = 20;
    try{
        node = &gv.addNode(pNode->getID(), sf::Vector2f(pNode->getPos().getX(), pNode->getPos().getY()));
    } catch (std::invalid_argument &e) {
        node = &gv.getNode(pNode->getID());
    }
    node->setColor(GraphViewer::PINK);
}

void GraphManager::drawDest(Node<struct NodeInfo> *pNode) {
    GraphViewer::Node* node;
    int factor = 20;
    try{
        node = &gv.addNode(pNode->getID(), sf::Vector2f(pNode->getPos().getX(), pNode->getPos().getY()));
    } catch (std::invalid_argument &e) {
        node = &gv.getNode(pNode->getID());
    }
    node->setColor(GraphViewer::YELLOW);
}

