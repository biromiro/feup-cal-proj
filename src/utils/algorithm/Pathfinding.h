//
// Created by nrtc on 07/05/2021.
//

#ifndef FEUP_CAL_PROJ_PATHFINDING_H
#define FEUP_CAL_PROJ_PATHFINDING_H


#include <graph/Graph.tpp>
#include <utils/utilitaryStructures/HeuristicNode.h>
#include <algorithm>

class Pathfinding {
public:
    template <class T>
    void static dijkstraAdaptation(Graph<NodeInfo>& graph, std::vector<Node<NodeInfo>*>& parks, int orig, int maxRadius);

    template <class T>
    bool static aStarAdaptation(Graph<T>& graph, int orig, int dest);

    template <class T>
    bool static dijkstraAdaptation(Graph<T>& graph, int orig, int dest);


    template <class T>
            bool static getOrderedPath(Graph<T>& graph, int origin, int dest, vector<Edge<T>*>& result);
};

template<class T>
void Pathfinding::dijkstraAdaptation(Graph<NodeInfo> &graph, std::vector<Node<NodeInfo>*>& parks, int orig, int maxRadius) {
    Node<T>* origin = graph.findNode(orig);

    if (origin == nullptr)
        throw std::invalid_argument("Dijkstra Origin Node");
    if (maxRadius < 0)
        throw std::invalid_argument("Dijkstra Radius");

    for(Node<T>* node: graph.getNodeSet()){
        node->setDist(INF);
        node->setPath(nullptr);
        node->setVisited(false);
    }

    std::priority_queue<Node<T> *, std::vector<Node<T> *>, CmpNodePtrs<T>> queue;
    Node<T>* curr = origin;

    curr->setDist(0);
    queue.push(curr);

    while (!queue.empty()) {
        if(curr->getDist() > maxRadius && !parks.empty()) break;
        curr = queue.top(); queue.pop();
        NodeInfo info = (NodeInfo)curr->getInfo();
        if (info.getType() == NodeType::PARK && info.getCurrentCapacity() < info.getMaxCapacity())
            parks.push_back(curr);

        for (auto edge : curr->getOutgoing()) {
            Node<T>* dest = edge->getDest();
            auto newDist = curr->getDist() + edge->getCost();
            if (newDist < dest->getDist()) {
                dest->setDist(newDist);
                dest->setPath(edge);
                queue.push(dest);
            }
        }
    }

    return;
}

template<class T>
bool Pathfinding::aStarAdaptation(Graph<T> &graph, int orig, int dest) {
    Node<T>* origin = graph.findNode(orig);
    Node<T>* destination = graph.findNode(dest);

    if(origin == nullptr || destination == nullptr) throw std::invalid_argument("Invalid Origin/Destination points!");

    for(Node<T>* node: graph.getNodeSet()){
        node->setDist(INF);
        node->setPath(nullptr);
    }
    origin->setDist(0);
    std::priority_queue<HeuristicNode<T>, vector<HeuristicNode<T>>, compare> pq{};
    pq.push(HeuristicNode<T>(origin, destination));
    while(!pq.empty()){
        HeuristicNode<T> current = pq.top();
        pq.pop();
        if(current.getCurrentNode() == destination) {
            return true;
        }
        for(Edge<T>* edge: current.getCurrentNode()->getOutgoing()){
            Node<T>* to = edge->getDest();
            double cost = current.getCurrentNode()->getDist() + edge->getCost();
            if(to->getDist() > cost){
                to->setDist(cost);
                to->setPath(edge);
                pq.push(HeuristicNode<T>(to, destination));
            }
        }
    }

    return false;
}

template<class T>
bool Pathfinding::getOrderedPath(Graph<T> &graph, int origin, int dest, vector<Edge<T>*>& result) {
    Node<T>* destination = graph.findNode(dest);
    Node<T>* source = graph.findNode(origin);
    Edge<T>* currentEdge = destination->getPath();
    while(currentEdge != nullptr){
        if (currentEdge->getOrig() == source)
            break;
        result.push_back(currentEdge);
        currentEdge = currentEdge->getOrig()->getPath();
    }
    result.push_back(currentEdge);
    std::reverse(result.begin(), result.end());
    return true;
}

template<class T>
bool Pathfinding::dijkstraAdaptation(Graph<T> &graph, int orig, int dest) {
    Node<T>* origin = graph.findNode(orig);
    Node<T>* destination = graph.findNode(dest);

    if (origin == nullptr || destination == nullptr)
        throw std::invalid_argument("Dijkstra Origin/Destination Node");


    for(Node<T>* node: graph.getNodeSet()){
        node->setDist(INF);
        node->setPath(nullptr);
    }

    std::priority_queue<Node<T> *, std::vector<Node<T> *>, CmpNodePtrs<T>> queue;
    Node<T>* curr = origin;

    curr->setDist(0);
    queue.push(curr);

    while (!queue.empty()) {
        curr = queue.top(); queue.pop();
        if(curr == destination) break;
        for (auto edge : curr->getOutgoing()) {
            Node<T>* dest = edge->getDest();
            auto newDist = curr->getDist() + edge->getCost();
            if (newDist < dest->getDist()) {
                dest->setDist(newDist);
                dest->setPath(edge);
                queue.push(dest);
            }
        }
    }
    return true;
}


#endif //FEUP_CAL_PROJ_PATHFINDING_H
