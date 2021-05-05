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
#include "MutablePriorityQueue.tpp"


/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */

template <class T>
class Graph {
    std::vector<Node<T> *> nodeSet;

public:
    Node<T>* findNode(const T &inf) const;
    std::vector<Node<T> *> getNodeSet() const;
    Node<T> *addNode(const T &in);
    Edge<T> *addEdge(const T &sourc, const T &dest, double capacity, double cost, double flow=0);
};

template <class T>
Node<T> * Graph<T>::addNode(const T &in) {
    Node<T> *v = findNode(in);
    if (v != nullptr)
        return v;
    v = new Node<T>(in);
    nodeSet.push_back(v);
    return v;
}

template <class T>
Edge<T> * Graph<T>::addEdge(const T &sourc, const T &dest, double capacity, double cost, double flow) {
    auto s = findNode(sourc);
    auto d = findNode(dest);
    if (s == nullptr || d == nullptr)
        return nullptr;
    Edge<T> *e = new Edge<T>(s, d, capacity, cost, flow);
    s->addEdge(e);
    return e;
}

template <class T>
Node<T>* Graph<T>::findNode(const T & inf) const {
    for (auto v : nodeSet)
        if (v->info == inf)
            return v;
    return nullptr;
}

template <class T>
std::vector<Node<T> *> Graph<T>::getNodeSet() const {
    return nodeSet;
}



#endif //FEUP_CAL_PROJ_GRAPH_TPP
