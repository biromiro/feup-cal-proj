//
// Created by emanu on 19-Nov-20.
//

#include "adminNotSet.h"

AdminNotSet::AdminNotSet(std::shared_ptr<Admin> admin, const std::string &message) : admin(std::move(admin)),std::runtime_error(message){}

const std::shared_ptr<Admin> &AdminNotSet::getAdmin() const {
    return admin;
}
