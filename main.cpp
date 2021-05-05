//
// Created by nrtc on 03/05/2021.
//

#include "src/utils/graph/Graph.tpp"

int main(){
    Graph<string> g;

    g.addNode("s");
    g.addNode("x");
    g.addNode("t");

    g.addEdge("s", "t", 3, 1);
    g.addEdge("s", "x", 2, 2);
    g.addEdge("x", "t", 1, 2);
    return 0;
}