//
// Created by nrtc on 07/05/2021.
//

#ifndef FEUP_CAL_PROJ_PATHFINDING_H
#define FEUP_CAL_PROJ_PATHFINDING_H


#include <graph/Graph.tpp>

class Pathfinding {
public:
    template <class T>
    void static dijkstraAdaptation(Graph<NodeInfo>& graph, std::vector<Node<NodeInfo>*>& parks, int orig, int maxRadius);

    template <class T>
    void static aStarAdapatation(Graph<T>& graph, Node<T>* origin, Node<T>* dest);
};

template<class T>
void Pathfinding::dijkstraAdaptation(Graph<NodeInfo> &graph, std::vector<Node<NodeInfo>*>& parks, int orig, int maxRadius) {
    Node<T>* origin = graph.findNode(orig);

    if (origin == nullptr)
        throw std::invalid_argument("Dijkstra Origin Node");
    if (maxRadius < 0)
        throw std::invalid_argument("Dijkstra Radius");


    for(Node<T>* node: graph.getNodeSet()){
        node->setDist(INF);
        node->setPath(nullptr);
        node->setVisited(false);
    }

    std::priority_queue<Node<T> *, std::vector<Node<T> *>, CmpNodePtrs<T>> queue;
    Node<T>* curr = origin;

    curr->setDist(0);
    queue.push(curr);

    while (!queue.empty() && curr->getDist() < maxRadius) {
        curr = queue.top(); queue.pop();
        NodeInfo info = (NodeInfo)curr->getInfo();
        if (info.getType() == NodeType::PARK && info.getCurrentCapacity() < info.getMaxCapacity())
            parks.push_back(curr);

        for (auto edge : curr->getOutgoing()) {
            Node<T>* dest = edge->getDest();
            auto newDist = curr->getDist() + edge->getCost();
            if (newDist < dest->getDist()) {
                dest->setDist(newDist);
                dest->setPath(edge);
                queue.push(dest);
            }
        }
    }
    return;
}

template<class T>
void Pathfinding::aStarAdapatation(Graph<T> &graph, Node<T> *origin, Node<T> *dest) {

}


#endif //FEUP_CAL_PROJ_PATHFINDING_H
