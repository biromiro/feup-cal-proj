//
// Created by emanu on 18-Nov-20.
//

#ifndef PROJECT_USERALREADYEXISTS_H
#define PROJECT_USERALREADYEXISTS_H

#include <iostream>
#include <exception>
#include <memory>
#include "../../model/user/user.h"

/**
 * @file userAlreadyExists.cpp
 *
 * @brief Exception for the case where the user being created already exists
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a user being created already exists
 *
 * Informs the user that the user being created already exists
 */
class UserAlreadyExists : public std::invalid_argument{
public:
    /**
     * Constructor of the UserAlreadyExists class
     *
     * @param user user that can't be created because he already exists
     * @param message message indicating the user being created already exists
     */
    UserAlreadyExists(User* user, const std::string & message);

    /**
     * Getter of the user that already exists
     *
     * @return user that already exists
     */
    [[nodiscard]] const User* getUser() const;

private:
    User* user;
};

#endif //PROJECT_USERALREADYEXISTS_H
