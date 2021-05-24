//
// Created by emanu on 19-Nov-20.
//

#ifndef PROJECT_ADMINALREADYSET_H
#define PROJECT_ADMINALREADYSET_H


#include <iostream>
#include <exception>
#include <memory>
#include "../../model/user/admin/admin.h"

/**
 * @file adminAlreadySet.cpp
 *
 * @brief Exception for the case where an admin is set but there is one already
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when an admin is set when there is one already
 *
 * Informs the user there is an admin already
 */
class AdminAlreadySet: public std::invalid_argument{
public:
    /**
     * Getter of the admin that was unsuccessfully set
     *
     * @return admin attempted to be set
     */
    [[nodiscard]] const std::shared_ptr<Admin> &getAdmin() const;

    /**
     * Constructor of the AdminAlreadySet class
     *
     * @param admin admin attempted to be set
     * @param message message indicating there was an admin already
     */
    AdminAlreadySet(std::shared_ptr<Admin> admin,const std::string & message);
private:
    std::shared_ptr<Admin> admin;
};

#endif //PROJECT_ADMINALREADYSET_H
