//
// Created by nrtc on 05/05/2021.
//

#ifndef FEUP_CAL_PROJ_GRAPHLOADER_TPP
#define FEUP_CAL_PROJ_GRAPHLOADER_TPP

#include <utils/graph/Graph.tpp>

enum NodeMode{
    COORDS,
    GRID
};

template <class T>
class GraphLoader {
public:
    GraphLoader(std::string nodes, std::string edges, NodeMode mode);
    Graph<T> getGraph();
private:
};

template <class T>
GraphLoader<T>::GraphLoader(std::string nodes, std::string edges, NodeMode mode) {

}
template <class T>
Graph<T> GraphLoader<T>::getGraph() {
    return nullptr;
}


#endif //FEUP_CAL_PROJ_GRAPHLOADER_TPP
