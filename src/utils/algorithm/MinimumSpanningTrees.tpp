//
// Created by nunoa on 08/05/21.
//

#include <stack>
#include "MinimumSpanningTrees.h"

template<class T>
std::vector<int>
MinimumSpanningTrees<T>::calculateTreeKruskal(const std::vector<Node<T> *> &nodes, Node<T> *origin,
                                              Node<T> *destination) {
    if(nodes.empty()) {
        return {origin->getID(), destination->getID()};
    }

    int edgesAccepted = 0;
    std::vector<Node<T>*> origNodes = nodes;
    origNodes.push_back(origin);
    UndirectedGraph<T> graph = UndirectedGraph<T>(origNodes);

    auto queue = MinimumSpanningTrees<T>::graphToQueue(graph);
    auto sets = MinimumSpanningTrees<T>::createSet(graph);

    while (edgesAccepted < graph.getNodeSet().size() - 1) {
        Edge<T> *edge = queue.top();
        queue.pop();

        if(edge->isSelected()) continue;

        DisjointSet *originSet = sets.findSet(edge->getOrig()->getID());
        DisjointSet *destSet = sets.findSet(edge->getDest()->getID());

        if (originSet != destSet) {
            edgesAccepted++;

            edge->select();
            edge->getReverse()->select();

            sets.linkSets(originSet, destSet);
        }
    }

    std::vector<int> result = MinimumSpanningTrees<T>::dfs(graph, graph.findNode(origin->getID()));
    result.push_back(destination->getID());

    graph.freeGraph();

    return result;
}

template<class T>
std::priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>>
MinimumSpanningTrees<T>::graphToQueue(UndirectedGraph<T> &graph) {
    auto queue = std::priority_queue<Edge<T> *, std::vector<Edge<T> *>, CmpEdgePtrs<T>>();

    for (auto pair : graph.getNodeSet()) {
        Node<T>* node = pair.second;
        for (Edge<T> *edge : node->getOutgoing()) {
            queue.push(edge);
        }
    }

    return queue;
}

template<class T>
DisjointSetGroup MinimumSpanningTrees<T>::createSet(UndirectedGraph<T> &graph) {
    DisjointSetGroup result;

    for (auto node : graph.getNodeSet()) {
        result.createSet(node.second->getID());
    }

    return result;
}

template<class T>
std::vector<int> MinimumSpanningTrees<T>::dfs(UndirectedGraph<T> &graph, Node<T> *origin) {
    Node<T> *v = origin;
    std::vector<int> nodes;

    std::stack<Node<T> *> nodeStack;
    Node<T> *curNode, *nextNode;
    nodeStack.push(v);

    for (auto node : graph.getNodeSet()) {
        node.second->setVisited(false);
    }

    while (!nodeStack.empty()) {
        curNode = nodeStack.top();
        if(!curNode->isVisited()) nodes.push_back(curNode->getID());
        curNode->setVisited(true);

        nodeStack.pop();

        for (Edge<T> *edge : curNode->getOutgoing()) {
            if (edge->isSelected()) {
                nextNode = edge->getDest();
                if (nextNode->isVisited()) continue;

                nodeStack.push(nextNode);
            }
        }
    }

    return nodes;
}
