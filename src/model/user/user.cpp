//
// Created by nrtc on 20/05/2021.
//

#include "user.h"

#include <utility>

User::User(std::string name, std::string password) : nickname(std::move(name)), password(std::move(password)) {}

const std::string &User::getNickname() const {
    return nickname;
}

const std::string &User::getPassword() const {
    return password;
}

bool User::operator<(const User &rhs) const {
    if (nickname < rhs.nickname)
        return true;
    if (rhs.nickname < nickname)
        return false;
    return password < rhs.password;
}

bool User::operator>(const User &rhs) const {
    return rhs < *this;
}

bool User::operator<=(const User &rhs) const {
    return !(rhs < *this);
}

bool User::operator>=(const User &rhs) const {
    return !(*this < rhs);
}

bool User::isAdmin() const {
    return false;
}
