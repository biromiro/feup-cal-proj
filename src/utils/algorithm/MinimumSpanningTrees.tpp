//
// Created by nunoa on 08/05/21.
//

#include <stack>
#include "MinimumSpanningTrees.h"

template<class T>
void MinimumSpanningTrees<T>::calculateTreeKruskal(UndirectedGraph<T> &graph, int originID) {
    int edgesAccepted = 0;

    auto queue = MinimumSpanningTrees<T>::graphToQueue(graph);
    auto sets = MinimumSpanningTrees<T>::createSet(graph);

    while(edgesAccepted < graph.getNodeSet().size() - 1) {
        Edge<T>* edge = queue.top();

        DisjointSet* originSet = sets.findSet(edge->getOrig()->getID());
        DisjointSet* destSet = sets.findSet(edge->getDest()->getID());

        if (originSet != destSet) {
            edgesAccepted++;

            edge->select();
            edge->getReverse()->select();

            sets.linkSets(originSet, destSet);
        }

        queue.pop();
    }

    MinimumSpanningTrees<int>::dfs(graph, originID);
}

template<class T>
priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>> MinimumSpanningTrees<T>::graphToQueue(UndirectedGraph<T> &graph) {
    auto queue = std::priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>>();

    for(Node<T>* node : graph.getNodeSet()) {
        for(Edge<T>* edge : node->getOutgoing()) {
            queue.push(edge);
        }
    }

    return queue;
}

template<class T>
DisjointSetGroup MinimumSpanningTrees<T>::createSet(UndirectedGraph<T> &graph) {
    DisjointSetGroup result;

    for(Node<T>* node : graph.getNodeSet()) {
        result.createSet(node->getID());
    }

    return result;
}

template<class T>
void MinimumSpanningTrees<T>::dfs(UndirectedGraph<T> &graph, int originID) {
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
