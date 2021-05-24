//
// Created by andremoreira9 on 5/23/21.
//

#include <fstream>
#include "parkFinalInfo.h"

void ParkFinalInfo::toJson(std::ofstream &journey) {
    journey << "        {\n"
            << "         \"id\": " << id << ",\n"
            << "         \"dist\": " << dist << ",\n"
            << "         \"price\": " << price << ",\n"
            << "         \"currCap\": " << currCap << ",\n"
            << "         \"maxCap\": " << maxCap << ",\n"
            << "         \"pos\": ["
            << y
            << "," << x
            << "]\n"
            << "        }";
}
