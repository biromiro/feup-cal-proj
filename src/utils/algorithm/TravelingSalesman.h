//
// Created by nunoa on 18/05/21.
//

#ifndef FEUP_CAL_PROJ_TRAVELINGSALESMAN_H
#define FEUP_CAL_PROJ_TRAVELINGSALESMAN_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include "graph/Node.tpp"
#include "algorithm/Distances.h"

template <class T>
class TravelingSalesman {
public:
    static std::vector<int> bruteForce(std::vector<Node<T>*> poi, Node<T>* origin, Node<T>* destination);
};

template<class T>
std::vector<int> TravelingSalesman<T>::bruteForce(std::vector<Node<T>*> poi, Node<T>* origin, Node<T>* destination) {
    std::vector<Node<T>*> shortest_path;
    double shortest_distance = std::numeric_limits<double>::infinity();

    if(poi.empty()) return {origin->getID(), destination->getID()};

    do {
        Node<T>* firstNode,* secondNode;

        double distance = 0;
        firstNode = origin;
        secondNode = poi.front();
        distance += Distances::getEuclideanDistance(firstNode->getPos(), secondNode->getPos());
        for(size_t i = 0; i < poi.size() - 1; i++) {
            firstNode = poi.at(i);
            secondNode = poi.at(i+1);

            distance += Distances::getEuclideanDistance(firstNode->getPos(), secondNode->getPos());
        }
        firstNode = poi.back();
        secondNode = destination;
        distance +=  Distances::getEuclideanDistance(firstNode->getPos(), secondNode->getPos());

        if(distance <= shortest_distance) {
            shortest_distance = distance;
            shortest_path = std::vector<Node<int>*>(poi.begin(), poi.end());
        }

    } while(std::next_permutation(poi.begin(), poi.end()));

    std::vector<int> shortest_id;

    shortest_id.push_back(origin->getID());
    for(Node<T>* node : shortest_path) {
        shortest_id.push_back(node->getID());
    }
    shortest_id.push_back(destination->getID());

    return shortest_id;
}



#endif //FEUP_CAL_PROJ_TRAVELINGSALESMAN_H
