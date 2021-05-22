//
// Created by nrtc on 20/05/2021.
//

#include "admin.h"

#include <utility>

Admin::Admin(std::string name, std::string password) : User(std::move(name), std::move(password)){}

bool Admin::isAdmin() const {
    return true;
}
