//
// Created by nrtc on 16/05/2021.
//

#include <utilitaryStructures/utilFunctions.h>
#include "GraphManager.h"

GraphManager::GraphManager(int height, int width, std::string path): imgHeight(height), imgWidth(width), imagePath(path) {
    // this->gv.setCenter(sf::Vector2f(height/2, width/2));
    if(path != "") this->gv.setBackground(path, sf::Vector2f(-height/2, -width/2));
    this->gv.setScale(10);
}

void GraphManager::buildPath(const vector<Edge<NodeInfo> *> &edges, GraphViewer::Color color) {
    if(edges.empty()) return;
    Node<NodeInfo>* origin = edges.at(0)->getOrig();
    GraphViewer::Node* orig, * dest;
    try{
        orig = &gv.addNode(origin->getID(), sf::Vector2f(origin->getPos().getX(), origin->getPos().getY()));
    } catch (std::invalid_argument &e) {
        orig = &gv.getNode(origin->getID());
    }
    orig->setColor(GraphViewer::WHITE);
    size_t numEdges = gv.getEdges().size();
    for(Edge<NodeInfo>* edge: edges){
        orig = &gv.getNode(edge->getOrig()->getID());
        try{
            dest = &gv.addNode(edge->getDest()->getID(), sf::Vector2f(edge->getDest()->getPos().getX(), edge->getDest()->getPos().getY()));
        } catch (std::invalid_argument &e) {
            dest = &gv.getNode(edge->getDest()->getID());
        }
        try{
            GraphViewer::Edge gvedge = gv.addEdge(numEdges, *orig, *dest, GraphViewer::Edge::EdgeType::DIRECTED);
            edgeIDs[edge] = numEdges++;
            //gvedge.setColor(color);
        } catch (std::invalid_argument &e) {}
        dest->setColor(color);
        dest->setSize(10);

    }
}

void GraphManager::showPath(const vector<Edge<NodeInfo> *> &edges, TravelType type){
    int speed = (type == TRAVEL) ? 50 : 200;
    GraphViewer::Node* orig, *dest;
    for(Edge<NodeInfo>* edge: edges){
        orig = &gv.getNode(edge->getOrig()->getID());
        dest = &gv.getNode(edge->getDest()->getID());
        this->gv.lock();
        dest->setSize(100.0);
        orig->setSize(10.0);
        this->gv.unlock();

        ms_sleep(speed);
    }
    this->gv.lock();
    dest->setSize(10.0);
    this->gv.unlock();

}

void GraphManager::show() {
    this->gv.createWindow(imgHeight,imgWidth);
}

void GraphManager::finish() {
    this->gv.join();
}

void GraphManager::drawPark(Node<NodeInfo> *&pNode) {
    GraphViewer::Node* node;
    try{
        node = &gv.addNode(pNode->getID(), sf::Vector2f(pNode->getPos().getX(), pNode->getPos().getY()));
    } catch (std::invalid_argument &e) {
        node = &gv.getNode(pNode->getID());
    }
    node->setColor(GraphViewer::PINK);
}

void GraphManager::drawDest(Node<NodeInfo> *pNode) {
    GraphViewer::Node* node;
    try{
        node = &gv.addNode(pNode->getID(), sf::Vector2f(pNode->getPos().getX(), pNode->getPos().getY()));
    } catch (std::invalid_argument &e) {
        node = &gv.getNode(pNode->getID());
    }
    node->setColor(GraphViewer::YELLOW);
}
