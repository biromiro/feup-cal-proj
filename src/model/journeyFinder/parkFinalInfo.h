//
// Created by andremoreira9 on 5/23/21.
//

#ifndef FEUP_CAL_PROJ_PARKFINALINFO_H
#define FEUP_CAL_PROJ_PARKFINALINFO_H

#include "parkFinalInfo.h"

class ParkFinalInfo {
    double dist;
    double price;
    int currCap;
    int maxCap;
    double x;
    double y;
    size_t id;
public:
    ParkFinalInfo(size_t id, double dist, double price, int currCap, int maxCap, double x, double y) :
        id(id), dist(dist), price(price), currCap(currCap), maxCap(maxCap), x(x), y(y) {}


    void toJson(std::ofstream &journey);
};

#endif //FEUP_CAL_PROJ_PARKFINALINFO_H
