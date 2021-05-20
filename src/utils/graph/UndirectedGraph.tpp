//
// Created by nunoa on 08/05/21.
//

#ifndef FEUP_CAL_PROJ_UNDIRECTEDGRAPH_TPP
#define FEUP_CAL_PROJ_UNDIRECTEDGRAPH_TPP

#include "Graph.tpp"
#include "algorithm/Distances.h"

template<class T>
class UndirectedGraph : public Graph<T> {
public:
    explicit UndirectedGraph(std::vector<Node<T> * > nodes);

    Edge<T> *addEdge(int srcID, int destID, double cost);
};

template<class T>
Edge<T> *UndirectedGraph<T>::addEdge(int srcID, int destID, double cost) {
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

template<class T>
UndirectedGraph<T>::UndirectedGraph(const std::vector<Node<T> * > nodes) {
    for (size_t i = 0; i < nodes.size(); i++) {
        Node<T> *firstNode = nodes.at(i);

        for (size_t j = i + 1; j < nodes.size(); j++) {
            Node<T> *secondNode = nodes.at(j);

            this->addNode(firstNode->getID(), firstNode->info, firstNode->getPos());
            this->addNode(secondNode->getID(), secondNode->info, secondNode->getPos());

            this->addEdge(firstNode->getID(), secondNode->getID(),
                          Distances::getEuclideanDistance(firstNode->getPos(), secondNode->getPos()));
        }
    }
}

#endif //FEUP_CAL_PROJ_UNDIRECTEDGRAPH_TPP
