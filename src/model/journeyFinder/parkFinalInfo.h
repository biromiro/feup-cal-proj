//
// Created by andremoreira9 on 5/23/21.
//

#ifndef FEUP_CAL_PROJ_PARKFINALINFO_H
#define FEUP_CAL_PROJ_PARKFINALINFO_H

#include "parkFinalInfo.h"

class ParkFinalInfo {
    double dist;
    double price;
    double x;
    double y;

public:
    ParkFinalInfo(double dist, double price, double x, double y) : dist(dist), price(price), x(x), y(y) {}


    void toJson(std::ofstream &journey);
};

#endif //FEUP_CAL_PROJ_PARKFINALINFO_H
