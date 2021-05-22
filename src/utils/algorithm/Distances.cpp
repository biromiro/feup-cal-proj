//
// Created by nrtc on 05/05/2021.
//

#include "Distances.h"

double Distances::dMeridian = 12340;
double Distances::dEquator = 24901;

double Distances::getEuclideanDistance(Position pos1, Position pos2) {
    if(pos1.getMode() != pos2.getMode()) throw std::invalid_argument("Incompatible modes upon distance calculation!");
    if(pos1.getMode() == COORDS) return getEuclideanDistanceCoords(pos1, pos2);
    else return getEuclideanDistanceGrid(pos1, pos2);
}

double Distances::getManhattanDistance(Position pos1, Position pos2) {
    if(pos1.getMode() != pos2.getMode()) throw std::invalid_argument("Incompatible modes upon distance calculation!");
    if(pos1.getMode() == COORDS) return getManhattanDistanceCoords(pos1, pos2);
    else return getManhattanDistanceGrid(pos1, pos2);
}

double Distances::getEuclideanDistanceCoords(Position pos1, Position pos2) {
    double dy = dMeridian * std::abs(pos1.getX() - pos2.getX()) / 180;
    double dx = dEquator * ( std::abs(pos1.getY() - pos2.getY()) / 360 ) * cos((pos1.getX() + pos2.getX())/2);
    return sqrt(pow(dx, 2) + pow(dy, 2)) * 1000.0;
}

double Distances::getEuclideanDistanceGrid(Position pos1, Position pos2) {
    return sqrt(pow(pos1.getX() - pos2.getX(), 2) + pow(pos1.getY() - pos2.getY(), 2));
}

double Distances::getManhattanDistanceCoords(Position pos1, Position pos2) {
    double dy = dMeridian * abs(pos1.getX() - pos2.getX()) / 180;
    double dx = dEquator * ( abs(pos1.getY() - pos2.getY()) / 360 ) * cos((pos1.getX() + pos2.getX())/2);
    return (dx + dy) * 1000.0;
}

double Distances::getManhattanDistanceGrid(Position pos1, Position pos2) {
    return abs(pos1.getX() - pos2.getX()) + abs(pos1.getY() - pos2.getY());
}
