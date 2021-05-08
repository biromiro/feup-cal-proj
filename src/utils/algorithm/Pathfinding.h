//
// Created by nrtc on 07/05/2021.
//

#ifndef FEUP_CAL_PROJ_PATHFINDING_H
#define FEUP_CAL_PROJ_PATHFINDING_H


#include <graph/Graph.tpp>

class Pathfinding {
public:
    template <class T>
    void static dijkstraAdaptation(Graph<T>& graph, int orig, int maxRadius);

    template <class T>
    void static aStarAdapatation(Graph<T>& graph, Node<T>* origin, Node<T>* dest);
};

template<class T>
void Pathfinding::dijkstraAdaptation(Graph<T> &graph, int orig, int maxRadius) {
    Node<T>* origin = graph.findNode(orig);

    for(Node<T>* node: graph.getNodeSet()){
        node->setDist(INF);
        node->setPath(nullptr);
    }

    MutablePriorityQueue<Node<T>> queue;
    Node<T>* curr = origin;

    curr->setDist(0);
    queue.insert(curr);

    while (!queue.empty()) {

    }
}

template<class T>
void Pathfinding::aStarAdapatation(Graph<T> &graph, Node<T> *origin, Node<T> *dest) {

}


#endif //FEUP_CAL_PROJ_PATHFINDING_H
