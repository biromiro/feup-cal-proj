//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_USER_H
#define FEUP_CAL_PROJ_USER_H

#include <iostream>
#include <string>

class User {
public:
    User(std::string  nickname, std::string  password);

    [[nodiscard]] const std::string &getNickname() const;

    [[nodiscard]] const std::string &getPassword() const;

    bool operator<(const User &rhs) const;

    bool operator>(const User &rhs) const;

    bool operator<=(const User &rhs) const;

    bool operator>=(const User &rhs) const;

    virtual bool isAdmin() const;

private:
    std::string nickname;
    std::string password;
};


#endif //FEUP_CAL_PROJ_USER_H
