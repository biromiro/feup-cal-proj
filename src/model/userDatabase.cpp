//
// Created by nrtc on 20/05/2021.
//

#include <algorithm>
#include <exception/userAlreadyExists/userAlreadyExists.h>
#include <exception/userNotFound/userNotFound.h>
#include "userDatabase.h"

UserDatabase::UserDatabase(UserManager *userManager, AdminManager *adminManager) :
userManager(userManager), adminManager(adminManager) {}

bool UserDatabase::add(User* user) {
    if (db.find(user) == db.end()){
        db.insert(user);
        return true;
    }
    throw UserAlreadyExists(user,"The user you're trying to add already exists!");
}

bool UserDatabase::remove(User* user) {
    if (db.find(user) != db.end()) {
        db.erase(user);
        return true;
    }
    throw UserNotFound(user,"The user you're looking for does not exist!");
}

bool UserDatabase::has(User* user) const {
    return db.find(user) != db.end();
}

bool UserDatabase::has(std::string nickname) const {
    return std::find_if(db.begin(),db.end(),
                        [&nickname](const User* user){return user->getNickname() == nickname;}) != db.end();
}


User *UserDatabase::get(std::string nickname) const {
    auto it = std::find_if(db.begin(),db.end(),
                           [&nickname](User* user){return user->getNickname() == nickname;});

    if(it != db.end()){
        return *it;
    }

    return nullptr;
}



