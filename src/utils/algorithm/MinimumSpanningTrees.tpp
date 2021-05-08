//
// Created by nunoa on 08/05/21.
//

#include <stack>
#include "MinimumSpanningTrees.h"

template<class T>
MinimumSpanningTrees<T>::MinimumSpanningTrees(UndirectedGraph<T> &graph) {
    this->graph = graph;
}

template<class T>
void MinimumSpanningTrees<T>::calculateTreeKruskal(int originID) {
    int edgesAccepted = 0;

    auto queue = this->graphToQueue();
    auto sets = this->createSet();

    while(edgesAccepted < graph.getNodeSet().size() - 1) {
        Edge<T>* edge = queue.top();

        std::cout << "edge from " << edge->getOrig()->getID() << " to "
        << edge->getDest()->getID() << " with cost " << edge->getCost() << std::endl;

        SetType* originSet = sets.findSet(edge->getOrig()->getID());
        SetType* destSet = sets.findSet(edge->getDest()->getID());

        if (originSet != destSet) {
            edgesAccepted++;

            edge->select();
            edge->getReverse()->select();

            sets.linkSets(originSet, destSet);
        }

        queue.pop();
    }

    dfs(originID);
}

template<class T>
priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>> MinimumSpanningTrees<T>::graphToQueue() {
    auto queue = std::priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>>();

    for(Node<T>* node : this->graph.getNodeSet()) {
        for(Edge<T>* edge : node->getOutgoing()) {
            queue.push(edge);
        }
    }

    return queue;
}

template<class T>
DisjointSet MinimumSpanningTrees<T>::createSet() {
    DisjointSet result;

    for(Node<T>* node : graph.getNodeSet()) {
        result.createSet(node->getID());
    }

    return result;
}

template<class T>
void MinimumSpanningTrees<T>::dfs(int originID) {
    Node<T>* v = graph.findNode(originID);
    if(v == nullptr) return;

    v->setPath(nullptr);

    std::stack<Node<T>*> nodeStack;
    Node<T>* curNode, * nextNode;
    nodeStack.push(v);

    for(Node<T>* node : graph.getNodeSet()) {
        node->setPath(nullptr);
        node->setVisited(false);
    }

    while(!nodeStack.empty()) {
        curNode = nodeStack.top();
        curNode->setVisited(true);

        nodeStack.pop();

        for(Edge<T>* edge : curNode->getOutgoing()) {
            if(edge->isSelected()) {
                nextNode = edge->getDest();
                if(nextNode->isVisited()) continue;

                nextNode->setPath(edge);
                nodeStack.push(nextNode);
            }
        }
    }
}
