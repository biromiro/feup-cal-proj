//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_NOFOUNDPATH_H
#define FEUP_CAL_PROJ_NOFOUNDPATH_H


#include <stdexcept>

class NoFoundPath : public std::invalid_argument {
public:
    explicit NoFoundPath(const std::string & message);
};

#endif //FEUP_CAL_PROJ_NOFOUNDPATH_H
