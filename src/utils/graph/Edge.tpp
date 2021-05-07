//
// Created by nrtc on 03/05/2021.
//

#ifndef FEUP_CAL_PROJ_EDGE_TPP
#define FEUP_CAL_PROJ_EDGE_TPP

template <class T> class Node;
template <class T> class Graph;

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */

template <class T>
class Edge {
    Node<T> * orig;
    Node<T> * dest;
    double cost;

    Edge(Node<T> *o, Node<T> *d, double cost=0);

public:
    Node<T> *getOrig() const;

    Node<T> *getDest() const;

    [[nodiscard]] double getCost() const;

    friend class Graph<T>;
    friend class Node<T>;
};

template <class T>
Edge<T>::Edge(Node<T> *o, Node<T> *d, double cost):
        orig(o), dest(d), cost(cost){}

template<class T>
Node<T> *Edge<T>::getOrig() const {
    return orig;
}

template<class T>
Node<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
double Edge<T>::getCost() const {
    return cost;
}

#endif //FEUP_CAL_PROJ_EDGE_TPP
