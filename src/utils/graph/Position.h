//
// Created by nrtc on 05/05/2021.
//

#ifndef FEUP_CAL_PROJ_POSITION_H
#define FEUP_CAL_PROJ_POSITION_H

#include <utils/graphLoad/NodeMode.h>

class Position {
public:
    explicit Position(NodeMode mode, double val1, double val2);
    double getX() const;
    double getY() const;
    NodeMode getMode();
private:
    NodeMode mode;
    double val1, val2;
};


#endif //FEUP_CAL_PROJ_POSITION_H
