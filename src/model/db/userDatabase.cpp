//
// Created by nrtc on 20/05/2021.
//

#include <algorithm>
#include <exception/userAlreadyExists/userAlreadyExists.h>
#include <exception/userNotFound/userNotFound.h>
#include <fstream>
#include <sstream>
#include <model/admin/admin.h>
#include "userDatabase.h"

UserDatabase::UserDatabase(const std::string& path) : path(path) {
    userManager = new UserManager();
    adminManager = new AdminManager();
    std::ifstream stream(path);
    if(!stream) return;
    std::string cur;
    while(std::getline(stream, cur)){
        std::stringstream ss(cur);
        std::string nickname, password;
        int val;
        ss >> val >> nickname >> password;
        if(val) db.insert(new Admin(nickname, password));
        else db.insert(new User(nickname, password));
    }
}

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

UserDatabase::~UserDatabase() {
    std::ofstream stream(path);
    for(User* user: db){
        if(user->isAdmin()) stream << 1;
        else stream << 0;
        stream << " " << user->getNickname() << " " << user->getPassword() << "\n";
        delete user;
    }
    delete userManager;
    delete adminManager;
}



