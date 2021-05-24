//
// Created by emanu on 19-Nov-20.
//

#ifndef PROJECT_ADMINNOTSET_H
#define PROJECT_ADMINNOTSET_H

#include <iostream>
#include <exception>
#include <memory>
#include "../../model/user/admin/admin.h"

/**
 * @file adminNotSet.cpp
 *
 * @brief Exception for the case where an admin is removed but there is no admin
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when an admin is removed when there is no admin
 *
 * Informs the user there is no admin
 */
class AdminNotSet : public std::runtime_error{
public:
    /**
     * Constructor for the AdminNotSet class
     *
     * @param admin admin attempted to be removed, but there's no admin
     * @param message message indicating there is no admin set yet
     */
    AdminNotSet(std::shared_ptr<Admin> admin,const std::string & message);

    /**
     * Getter of the admin that was attempted to be removed
     *
     * @return admin attempted to be removed
     */
    [[nodiscard]] const std::shared_ptr<Admin> &getAdmin() const;

private:
    std::shared_ptr<Admin> admin;
};


#endif //PROJECT_ADMINNOTSET_H
