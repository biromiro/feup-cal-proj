//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H
#define FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H

#include "graph/UndirectedGraph.tpp"
#include "disjointSet/DisjointSet.h"

template<class T>
struct CmpEdgePtrs {
    bool operator()(const Edge<T> * lhs, const Edge<T> * rhs) const {
        return lhs->getCost() > rhs->getCost();
    }
};

template<class T>
class MinimumSpanningTrees {
private:
    UndirectedGraph<T> graph;

    void dfs(int originID);
    std::priority_queue<Edge<T>*, std::vector<Edge<T>*>, CmpEdgePtrs<T>> graphToQueue();
    DisjointSet createSet();
public:
    explicit MinimumSpanningTrees(UndirectedGraph<T> &graph);

    void calculateTreeKruskal(int originID);
};

template<class T>
MinimumSpanningTrees<T>::MinimumSpanningTrees(UndirectedGraph<T> &graph) {
    this->graph = graph;
}

template<class T>
void MinimumSpanningTrees<T>::calculateTreeKruskal(int originID) {
    int edgesAccepted = 0;

    auto queue = this->graphToQueue();
    auto sets = this->createSet();
}

template<class T>
priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>> MinimumSpanningTrees<T>::graphToQueue() {
    auto queue = std::priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>>();

    for(Node<T>* node : this->graph.getNodeSet()) {
        for(Edge<T>* edge : node->getOutgoing()) {
            queue.push(edge);
        }
    }

    return queue;
}

template<class T>
DisjointSet MinimumSpanningTrees<T>::createSet() {
    DisjointSet result;

    for(Node<T>* node : graph.getNodeSet()) {
        result.createSet(node->getID());
    }

    return result;
}

#endif //FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H
