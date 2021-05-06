//
// Created by nrtc on 05/05/2021.
//

#include "Position.h"

Position::Position(NodeMode mode, double val1, double val2) {
    this->val1 = val1;
    this->val2 = val2;
    this->mode = mode;
}

double Position::getX() {
    return val1;
}

double Position::getY() {
    return val2;
}

NodeMode Position::getMode() {
    return mode;
}
