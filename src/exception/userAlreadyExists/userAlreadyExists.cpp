//
// Created by emanu on 18-Nov-20.
//

#include "userAlreadyExists.h"

UserAlreadyExists::UserAlreadyExists(User* user, const std::string & message):  user(std::move(user)),std::invalid_argument(message){}

const User* UserAlreadyExists::getUser() const {
    return user;
}
