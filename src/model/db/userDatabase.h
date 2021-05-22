//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_USERDATABASE_H
#define FEUP_CAL_PROJ_USERDATABASE_H


#include <string>
#include <set>
#include <unordered_set>
#include <model/user/user.h>
#include <model/user/userManager.h>
#include <model/admin/adminManager.h>

/**
 * Hash for the unordered set of users
 */
struct userHash{
    int operator()(User* user) const{
        int v = 0;
        for(const auto& elem: user->getNickname()){
            v = v*37 + elem;
        }
        return v;
    }
    bool operator()(User* user1, User* user2) const{
        return user1->getNickname() == user2->getNickname();
    }
};

typedef std::unordered_set<User*,userHash,userHash> userDB;

class UserDatabase {
public:
    UserDatabase(const std::string& path = "");
    User* get(std::string nickname) const;
    bool add(User *user);
    bool remove(User *user);
    bool has(User *user) const;
    bool has(std::string nickname) const;

    virtual ~UserDatabase();

private:
    UserManager* userManager;
    AdminManager* adminManager;
    std::string path;
    userDB db;
};


#endif //FEUP_CAL_PROJ_USERDATABASE_H
