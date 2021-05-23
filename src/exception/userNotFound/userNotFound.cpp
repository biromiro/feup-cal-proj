//
// Created by emanu on 19-Nov-20.
//

#include "userNotFound.h"

UserNotFound::UserNotFound(User* user, const std::string &message) : user(std::move(user)),std::invalid_argument(message){}

const User* UserNotFound::getUser() const {
    return user;
}
