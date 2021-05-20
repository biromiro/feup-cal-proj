//
// Created by nrtc on 05/05/2021.
//

#ifndef FEUP_CAL_PROJ_DISTANCES_H
#define FEUP_CAL_PROJ_DISTANCES_H

#include <iostream>
#include <stdexcept>      // std::invalid_argument
#include <cmath>
#include <utils/graph/Position.h>

class Distances {
public:
    double static getEuclideanDistance(Position pos1, Position pos2);
    double static getManhattanDistance(Position pos1, Position pos2);
private:
    double static dMeridian;
    double static dEquator;
    double static getEuclideanDistanceCoords(Position pos1, Position pos2);
    double static getEuclideanDistanceGrid(Position pos1, Position pos2);
    double static getManhattanDistanceCoords(Position pos1, Position pos2);
    double static getManhattanDistanceGrid(Position pos1, Position pos2);
};


#endif //FEUP_CAL_PROJ_DISTANCES_H
