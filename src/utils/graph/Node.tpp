#ifndef FEUP_CAL_PROJ_NODE_TPP
#define FEUP_CAL_PROJ_NODE_TPP

#include "Edge.tpp"
#include <limits>
#include "MutablePriorityQueue.tpp"
#include "Position.h"

template <class T> class Graph;
template <class T> class UndirectedGraph;

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
    int ID = 0;
    int sccsID = 0;
    int queueIndex = 0;
    int lowlink = 0;
    bool inStack = false;
    Position pos;
    void addEdge(Edge<T> *e);
    bool operator<(Node<T> & node) const;
    Node(int id, T in, Position pos);

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
    void setID(int newID);
    int getID() const;
    int getSCCSID() const;
    void setSCCSID(int sccsId);
    int getLowlink() const;
    void setLowlink(int lowlink);
    bool isInStack() const;
    void setInStack(bool inStack);
    const Position &getPos() const;
    void setPos(const Position &pos);

    friend class UndirectedGraph<T>;
    friend class Graph<T>;
    friend class MutablePriorityQueue<Node<T>>;
};


template<class T>
void Edge<T>::select() {
    this->selected = true;
}

template<class T>
bool Edge<T>::isSelected() const {
    return this->selected;
}

template<class T>
Edge<T> *Edge<T>::getReverse() const {
    return reverse;
}

template <class T>
Node<T>::Node(int id, T in, Position pos): ID(id), info(in), pos(pos) {}

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
void Node<T>::setID(int newID) {
    Node::ID = newID;
}

template<class T>
int Node<T>::getID() const {
    return ID;
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

template<class T>
int Node<T>::getSCCSID() const {
    return sccsID;
}

template<class T>
void Node<T>::setSCCSID(int sccsId) {
    sccsID = sccsId;
}

template<class T>
const Position &Node<T>::getPos() const {
    return pos;
}

template<class T>
void Node<T>::setPos(const Position &pos) {
    Node::pos = pos;
}

template<class T>
struct CmpNodePtrs {
    bool operator()(const Node<T> * lhs, const Node<T> * rhs) const {
        return lhs->getDist() > rhs->getDist();
    }
};


#endif //FEUP_CAL_PROJ_NODE_TPP
