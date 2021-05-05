//
// Created by nrtc on 05/05/2021.
//

#ifndef FEUP_CAL_PROJ_CONNECTIVITY_TPP
#define FEUP_CAL_PROJ_CONNECTIVITY_TPP

#include <utils/graph/Graph.tpp>
#include <stack>

template <class T>
class Connectivity {
public:
    explicit Connectivity(Graph<T>& graph);
    bool isConnected();
    int getNumConnectedComponents();
private:
    int sccs = INF;
    Graph<T> currentGraph;
    bool calculateTarjan();
    void dfs(int& currentID, Node<T> *node, std::stack<Node<T>*>& stack);
};

template<class T>
Connectivity<T>::Connectivity(Graph<T> &graph) {
    this->currentGraph = graph;
}

template<class T>
bool Connectivity<T>::isConnected() {
    return calculateTarjan();
}

template<class T>
int Connectivity<T>::getNumConnectedComponents() {
    if(sccs == INF) calculateTarjan();
    return sccs;
}

template<class T>
bool Connectivity<T>::calculateTarjan() {
    sccs = 0;
    int currentID = 0;
    std::stack<Node<T>*> stack = std::stack<T>();

    for(Node<T>* node: currentGraph.getNodeSet())
        node->setVisited(false);

    for(Node<T>* node: currentGraph.getNodeSet())
        if(node->isVisited()) dfs(currentID, node, stack);

    return sccs == 1;
}

template<class T>
void Connectivity<T>::dfs(int &currentID, Node<T> *node, std::stack<Node<T>*> &stack) {
    stack.push(node);
    node->setInStack(true);
    node->setId(currentID);
    node->setLowlink(currentID);
    currentID++;

    for(Node<T>* adjacent: node->getOutgoing()){
        if(adjacent->isVisited()) dfs(currentID, adjacent, stack);
        if(node->isInStack()) adjacent->setLowlink(std::min(adjacent->getLowlink(), node->getLowlink()));
    }

    if(node->getId() == node->getLowlink()){
        Node<T> * cur;
        while((cur = stack.top()) != node){
            cur->setInStack(false);
            stack.pop()
        }
        cur->setInStack(false);
        stack.pop();
        sccs++;
    }
}


#endif //FEUP_CAL_PROJ_CONNECTIVITY_TPP
