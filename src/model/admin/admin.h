//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_ADMIN_H
#define FEUP_CAL_PROJ_ADMIN_H

#include <iostream>
#include <string>
#include <model/user/user.h>

class Admin : public User{
public:
    Admin(std::string nickname, std::string password);
    bool isAdmin() const;
};



#endif //FEUP_CAL_PROJ_ADMIN_H
