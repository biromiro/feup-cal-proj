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
    static std::vector<Node<T>*> getTour(std::vector<Node<T>*> poi, Node<T>* origin);
};

template <class T>
std::vector<Node<T>*> NearestNeighbour<T>::getTour(std::vector<Node<T>*> poi, Node<T>* origin) {
    std::vector<Node<T>*> tour = {origin};
    Node<T>* last = origin;

    while(!poi.empty()) {
        double minDist = std::numeric_limits<double>::infinity();
        typename std::vector<Node<T>*>::iterator next = poi.end();

        for(auto nodeIt = poi.begin(); nodeIt != poi.end(); nodeIt++) {
            double dist = Distances::getEuclideanDistance(last->getPos(), (*nodeIt)->getPos());
            if(dist < minDist) {
                minDist = dist;
                next = nodeIt;
            }
        }

        tour.push_back(*next);
        last = *next;
        poi.erase(next);
    }

    return tour;
}

#endif //FEUP_CAL_PROJ_NEARESTNEIGHBOUR_H
