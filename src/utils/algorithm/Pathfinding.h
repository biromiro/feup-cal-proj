//
// Created by nrtc on 07/05/2021.
//

#ifndef FEUP_CAL_PROJ_PATHFINDING_H
#define FEUP_CAL_PROJ_PATHFINDING_H


#include <graph/Graph.tpp>

class Pathfinding {
public:
    template <class T>
    void static dijkstraAdaptation(Graph<T>& graph, Node<T>* origin);

    template <class T>
    void static aStarAdapatation(Graph<T>& graph, Node<T>* origin, Node<T>* dest);
};

template<class T>
void Pathfinding::dijkstraAdaptation(Graph<T> &graph, Node<T> *origin) {

}

template<class T>
void Pathfinding::aStarAdapatation(Graph<T> &graph, Node<T> *origin, Node<T> *dest) {

}


#endif //FEUP_CAL_PROJ_PATHFINDING_H
