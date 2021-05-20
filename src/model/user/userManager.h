//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_USERMANAGER_H
#define FEUP_CAL_PROJ_USERMANAGER_H


#include "user.h"

class UserManager {

    User *get(std::__cxx11::basic_string<char> nickname) const;
};


#endif //FEUP_CAL_PROJ_USERMANAGER_H
