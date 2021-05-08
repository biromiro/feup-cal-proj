//
// Created by nunoa on 08/05/21.
//

#ifndef FEUP_CAL_PROJ_UNDIRECTEDGRAPH_TPP
#define FEUP_CAL_PROJ_UNDIRECTEDGRAPH_TPP

#include "Graph.tpp"

template <class T>
class UndirectedGraph : public Graph<T> {
public:
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
    d->addEdge(e);
    return e;
}

#endif //FEUP_CAL_PROJ_UNDIRECTEDGRAPH_TPP
