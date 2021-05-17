//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H
#define FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H

#include "graph/UndirectedGraph.tpp"
#include "disjointSet/DisjointSetGroup.h"

template<class T>
struct CmpEdgePtrs {
    bool operator()(const Edge<T> * lhs, const Edge<T> * rhs) const {
        return lhs->getCost() > rhs->getCost();
    }
};

template<class T>
class MinimumSpanningTrees {
private:
    static void dfs(UndirectedGraph<T> &graph, int originID);
    static std::priority_queue<Edge<T>*, std::vector<Edge<T>*>, CmpEdgePtrs<T>> graphToQueue(UndirectedGraph<T> &graph);
    static DisjointSetGroup createSet(UndirectedGraph<T> &graph);
public:
    static void calculateTreeKruskal(UndirectedGraph<T> &graph, int originID);
};

#include "MinimumSpanningTrees.tpp"

#endif //FEUP_CAL_PROJ_MINIMUMSPANNINGTREES_H
