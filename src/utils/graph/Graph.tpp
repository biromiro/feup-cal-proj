//
// Created by nrtc on 03/05/2021.
//

#ifndef FEUP_CAL_PROJ_GRAPH_TPP
#define FEUP_CAL_PROJ_GRAPH_TPP

#include "Node.tpp"
#include "Edge.tpp"
#include <vector>
#include <queue>
#include <iostream>
#include <graphLoad/MapData.h>
#include "MutablePriorityQueue.tpp"


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

template <class T>
class Graph {
    std::vector<Node<T> *> nodeSet;

public:
    Node<T>* findNode(int id) const;
    std::vector<Node<T> *> getNodeSet() const;
    Node<T> *addNode(int ID, const T &in, Position pos);

    virtual Edge<T> *addEdge(int srcID, int destID, double cost);
};

template <class T>
Node<T> * Graph<T>::addNode(int ID, const T &in, Position pos) {
    Node<T> *v = findNode(ID);
    if (v != nullptr)
        return v;
    v = new Node<T>(ID, in, pos);
    nodeSet.push_back(v);
    return v;
}

template <class T>
std::vector<Node<T> *> Graph<T>::getNodeSet() const {
    return nodeSet;
}

template<class T>
Node<T> *Graph<T>::findNode(int id) const {
    for (Node<T>* v : nodeSet)
        if (v->getID() == id)
            return v;
    return nullptr;
}

template<class T>
Edge<T> *Graph<T>::addEdge(int srcID, int destID, double cost) {
    auto s = this->findNode(srcID);
    auto d = this->findNode(destID);
    if (s == nullptr || d == nullptr)
        return nullptr;
    auto *e = new Edge<T>(s, d, cost);
    s->addEdge(e);
    auto *e2 = new Edge<T>(d, s, cost);
    d->addEdge(e2);

    e->reverse = e2;
    e2->reverse = e;
    return e;
}


#endif //FEUP_CAL_PROJ_GRAPH_TPP
