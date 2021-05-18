//
// Created by nunoa on 17/05/21.
//

#ifndef FEUP_CAL_PROJ_NEARESTNEIGHBOUR_H
#define FEUP_CAL_PROJ_NEARESTNEIGHBOUR_H

#include <vector>
#include "graph/Node.tpp"
#include "Distances.h"

template <class T>
class NearestNeighbour {
public:
    static std::vector<int> getTour(std::vector<Node<T>*> poi, Node<T>* origin, Node<T>* destination);
};

template <class T>
std::vector<int> NearestNeighbour<T>::getTour(std::vector<Node<T>*> poi, Node<T>* origin, Node<T>* destination) {
    std::vector<int> tour = {origin->getID()};
    Node<T>* last = origin;

    while(!poi.empty()) {
        double minDist = std::numeric_limits<double>::infinity();
        auto next = poi.end();

        for(auto nodeIt = poi.begin(); nodeIt != poi.end(); nodeIt++) {
            double dist = Distances::getEuclideanDistance(last->getPos(), (*nodeIt)->getPos());
            if(dist < minDist) {
                minDist = dist;
                next = nodeIt;
            }
        }

        tour.push_back((*next)->getID());
        last = *next;
        poi.erase(next);
    }

    tour.push_back(destination->getID());
    return tour;
}

#endif //FEUP_CAL_PROJ_NEARESTNEIGHBOUR_H
