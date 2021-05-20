//
// Created by nrtc on 07/05/2021.
//

#ifndef FEUP_CAL_PROJ_HEURISTICNODE_H
#define FEUP_CAL_PROJ_HEURISTICNODE_H

#include <utils/graph/Node.tpp>
#include <utils/algorithm/Distances.h>

template <class T>
class HeuristicNode{
public:
    HeuristicNode(Node<T> *node, Node<T>* dest);
    void calculateHeuristicDist(Node<T>* destinationNode);
    bool operator<(const HeuristicNode<T> & node) const;
    Node<T> *getCurrentNode() const;
    [[nodiscard]] double getHeuristicDist() const;

private:
    Node<T>* currentNode;
    double heuristicDist{};
};

template<class T>
bool HeuristicNode<T>::operator<(const HeuristicNode<T> &node) const{
    return this->heuristicDist < node.heuristicDist;
}

template<class T>
HeuristicNode<T>::HeuristicNode(Node<T> *node, Node<T>* dest) {
    currentNode = node;
    calculateHeuristicDist(dest);
}

template<class T>
void HeuristicNode<T>::calculateHeuristicDist(Node<T>* destinationNode) {
    heuristicDist = Distances::getEuclideanDistance(currentNode->getPos(), destinationNode->getPos());
}

template<class T>
Node<T> *HeuristicNode<T>::getCurrentNode() const {
    return currentNode;
}

template<class T>
double HeuristicNode<T>::getHeuristicDist() const {
    return heuristicDist;
}

struct compare
{
    template<class T>
    bool operator()(const HeuristicNode<T> & a, const HeuristicNode<T> & b)
    {
        return b < a;
    }
};

#endif //FEUP_CAL_PROJ_HEURISTICNODE_H
