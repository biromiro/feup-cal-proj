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

#include "MinimumSpanningTrees.tpp"

#endif //FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H
