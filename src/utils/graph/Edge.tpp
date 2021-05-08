//
// Created by nrtc on 03/05/2021.
//

#ifndef FEUP_CAL_PROJ_EDGE_TPP
#define FEUP_CAL_PROJ_EDGE_TPP

template <class T> class Node;
template <class T> class Graph;
template <class T> class UndirectedGraph;

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

    double getCost() const;

    friend class UndirectedGraph<T>;
    friend class Graph<T>;
    friend class Node<T>;
};

template <class T>
Edge<T>::Edge(Node<T> *o, Node<T> *d, double cost):
        orig(o), dest(d), cost(cost){}



#endif //FEUP_CAL_PROJ_EDGE_TPP
