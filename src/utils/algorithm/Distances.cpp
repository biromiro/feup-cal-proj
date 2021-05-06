//
// Created by nrtc on 05/05/2021.
//

#include "Distances.h"

double Distances::getEuclideanDistance(Position pos1, Position pos2) {
    if(pos1.getMode() != pos2.getMode()) throw std::invalid_argument("Incompatible modes upon distance calculation!");
    if(pos1.getMode() == COORDS) return getEuclideanDistanceCoords(pos1, pos2);
    else return getEuclideanDistanceGrid(pos1, pos2);
}

double Distances::getManhattanDistance(Position pos1, Position pos2) {
    return 0;
}

double Distances::getEuclideanDistanceCoords(Position pos1, Position pos2) {
    return 0;
}

double Distances::getEuclideanDistanceGrid(Position pos1, Position pos2) {
    return sqrt(pow(pos1.getX() - pos2.getX(), 2) + pow(pos1.getY() - pos2.getY(), 2));
}
