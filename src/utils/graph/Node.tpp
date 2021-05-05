#ifndef FEUP_CAL_PROJ_NODE_TPP
#define FEUP_CAL_PROJ_NODE_TPP

#include "Edge.tpp"
#include <limits>
#include "MutablePriorityQueue.tpp"

template <class T> class Graph;

constexpr auto INF = std::numeric_limits<double>::max();

/*
 * ================================================================================================
 * Class Node
 * ================================================================================================
 */

template <class T>
class Node {
    T info;
    std::vector<Edge<T> *> outgoing;
    std::vector<Edge<T> *> incoming;

    bool visited = false;
    Edge<T> *path;
    double dist = INF;
    int id = 0;
    int queueIndex = 0;
    int lowlink = 0;
    bool inStack = false;

    Node(T in);
    void addEdge(Edge<T> *e);
    bool operator<(Node<T> & node) const;

public:
    T getInfo() const;
    std::vector<Edge<T> *> getIncoming() const;
    std::vector<Edge<T> *> getOutgoing() const;
    void setVisited(bool visited);
    void setPath(Edge<T> *path);
    void setDist(double dist);
    bool isVisited() const;
    Edge<T> *getPath() const;
    double getDist() const;
    void setId(int id);
    int getId() const;
    int getLowlink() const;
    void setLowlink(int lowlink);
    bool isInStack() const;
    void setInStack(bool inStack);
    friend class Graph<T>;
    friend class MutablePriorityQueue<Node<T>>;
};


template <class T>
Node<T>::Node(T in): info(in) {}

template <class T>
void Node<T>::addEdge(Edge<T> *e) {
    outgoing.push_back(e);
    e->dest->incoming.push_back(e);
}

template <class T>
bool Node<T>::operator<(Node<T> & node) const {
    return this->dist < node.dist;
}

template <class T>
T Node<T>::getInfo() const {
    return this->info;
}

template <class T>
vector<Edge<T> *>  Node<T>::getIncoming() const {
    return this->incoming;
}

template <class T>
vector<Edge<T> *>  Node<T>::getOutgoing() const {
    return this->outgoing;
}

template<class T>
void Node<T>::setVisited(bool newVisited) {
    Node::visited = newVisited;
}

template<class T>
void Node<T>::setPath(Edge<T> *newPath) {
    Node::path = newPath;
}

template<class T>
void Node<T>::setDist(double newDist) {
    Node::dist = newDist;
}

template<class T>
bool Node<T>::isVisited() const {
    return visited;
}

template<class T>
Edge<T> *Node<T>::getPath() const {
    return path;
}

template<class T>
double Node<T>::getDist() const {
    return dist;
}

template<class T>
void Node<T>::setId(int id) {
    Node::id = id;
}

template<class T>
int Node<T>::getId() const {
    return id;
}

template<class T>
int Node<T>::getLowlink() const {
    return lowlink;
}

template<class T>
void Node<T>::setLowlink(int lowlink) {
    Node::lowlink = lowlink;
}

template<class T>
bool Node<T>::isInStack() const {
    return inStack;
}

template<class T>
void Node<T>::setInStack(bool inStack) {
    Node::inStack = inStack;
}


#endif //FEUP_CAL_PROJ_NODE_TPP
