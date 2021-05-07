//
// Created by nrtc on 07/05/2021.
//

#ifndef FEUP_CAL_PROJ_PATHFINDING_H
#define FEUP_CAL_PROJ_PATHFINDING_H


#include <graph/Graph.tpp>
#include <utils/utilitaryStructures/HeuristicNode.h>

class Pathfinding {
public:
    template <class T>
    void static dijkstraAdaptation(Graph<T>& graph, Node<T>* origin);

    template <class T>
    bool static aStarAdaptation(Graph<T>& graph, int orig, int dest);
};

template<class T>
void Pathfinding::dijkstraAdaptation(Graph<T> &graph, Node<T> *origin) {

}

template<class T>
bool Pathfinding::aStarAdaptation(Graph<T> &graph, int orig, int dest) {
    Node<T>* origin = graph.findNode(orig);
    Node<T>* destination = graph.findNode(dest);
    for(Node<T>* node: graph.getNodeSet()){
        node->setDist(INF);
        node->setPath(nullptr);
    }
    origin->setDist(0);
    std::priority_queue<HeuristicNode<T>> pq{};
    pq.push(HeuristicNode<T>(origin, destination));
    while(!pq.empty()){
        HeuristicNode<T> current = pq.top();
        pq.pop();
        if(current.getCurrentNode() == destination) return true;
        for(Edge<T>* edge: current.getCurrentNode()->getOutgoing()){
            Node<T>* to = edge->getDest();
            double cost = current.getCurrentNode()->getDist() + edge->getCost();
            if(to->getDist() == INF || to->getDist() > cost){
                to->setDist(cost);
                to->setPath(edge);
                pq.push(HeuristicNode<T>(to, destination));
            }
        }
    }
    return false;
}


#endif //FEUP_CAL_PROJ_PATHFINDING_H
