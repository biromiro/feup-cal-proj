//
// Created by emanu on 19-Nov-20.
//

#ifndef PROJECT_USERNOTFOUND_H
#define PROJECT_USERNOTFOUND_H

#include <iostream>
#include <exception>
#include <memory>
#include "../../model/user/user.h"

/**
 * @file userNotFound.cpp
 *
 * @brief Exception for the case where the user being eliminated does not exist
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a user is being eliminated but cannot be found, since he doesn't exist
 *
 * Informs the user that the user being eliminated couldn't be found
 */
class UserNotFound : public std::invalid_argument{
public:
    /**
     * Constructor of the UserNotFound class
     *
     * @param user user that couldn't be found
     * @param message message indicating the user being eliminated doesn't exists
     */
    UserNotFound(User* user, const std::string & message);

    /**
     * Getter of the user that couldn't be found
     *
     * @return user that couldn't be found
     */
    [[nodiscard]] const User* getUser() const;

private:
    User* user;

};


#endif //PROJECT_USERNOTFOUND_H
