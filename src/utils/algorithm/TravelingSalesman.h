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

struct intPairHasher {
    std::size_t operator()(const pair<int,int> &k) const
    {
        std::size_t hash = 0;

        std::hash<int> hasher;
        hash ^= hasher(k.first) + 0x9e3779b9 + (hash<<6) + (hash>>2);
        hash ^= hasher(k.second) + 0x9e3779b9 + (hash<<6) + (hash>>2);

        return hash;
    }
};

template <class T>
class TravelingSalesman {
private:
    static double calculateDistance(std::unordered_map<std::pair<int, int>, double, intPairHasher> &distances, Node<T>* first, Node<T>* second);
public:
    static std::vector<int> bruteForce(std::vector<Node<T>*> poi, Node<T>* origin, Node<T>* destination);
};

template<class T>
std::vector<int> TravelingSalesman<T>::bruteForce(std::vector<Node<T>*> poi, Node<T>* origin, Node<T>* destination) {
    std::vector<Node<T>*> shortest_path;
    std::unordered_map<std::pair<int, int>, double, intPairHasher> distances;
    double shortest_distance = std::numeric_limits<double>::infinity();

    if(poi.empty()) return {};

    do {
        Node<T>* firstNode,* secondNode;

        double distance = 0;
        firstNode = origin;
        secondNode = poi.front();
        distance +=  TravelingSalesman<T>::calculateDistance(distances, firstNode, secondNode);
        for(size_t i = 0; i < poi.size() - 1; i++) {
            firstNode = poi.at(i);
            secondNode = poi.at(i+1);

            distance +=  TravelingSalesman<T>::calculateDistance(distances, firstNode, secondNode);
        }
        firstNode = poi.back();
        secondNode = destination;
        distance +=  TravelingSalesman<T>::calculateDistance(distances, firstNode, secondNode);

        if(distance <= shortest_distance) {
            shortest_distance = distance;
            shortest_path = poi;
        }

    } while(std::next_permutation(poi.begin(), poi.end()));

    std::vector<int> shortest_id;

    for(Node<T>* node : shortest_path) {
        shortest_id.push_back(node->getID());
    }

    return shortest_id;
}

template<class T>
double TravelingSalesman<T>::calculateDistance(std::unordered_map<std::pair<int, int>, double, intPairHasher> &distances, Node<T>* first, Node<T>* second) {
    std::pair<int, int> pair  = std::minmax(first->getID(), second->getID());
    auto it = distances.find(pair);
    double distance;

    if(it == distances.end()) {
        distance = Distances::getEuclideanDistance(first->getPos(), second->getPos());
        distances[pair] = distance;
    } else {
        distance = it->second;
    }

    return distance;
}


#endif //FEUP_CAL_PROJ_TRAVELINGSALESMAN_H
