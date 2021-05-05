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
    double capacity;
    double cost;
    double flow;

    Edge(Node<T> *o, Node<T> *d, double capacity, double cost=0, double flow=0);

public:
    friend class Graph<T>;
    friend class Node<T>;
    double getFlow() const;
};

template <class T>
Edge<T>::Edge(Node<T> *o, Node<T> *d, double capacity, double cost, double flow):
        orig(o), dest(d), capacity(capacity), cost(cost), flow(flow){}

template <class T>
double  Edge<T>::getFlow() const {
    return this->flow;
}


#endif //FEUP_CAL_PROJ_EDGE_TPP
