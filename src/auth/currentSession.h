//
// Created by biromiro on 20/05/21.
//

#ifndef PROJECT_CURRENTSESSION_H
#define PROJECT_CURRENTSESSION_H

#include <iostream>
#include <model/user/user.h>
#include <src/model/db/userDatabase.h>

class CurrentSession{
private:
    UserDatabase* userDatabase;
    User* currentUser;
public:
    /**
     * Current Session's default constructor
     */
    CurrentSession();

    /**
     * Current Session's constructor
     * @param userDatabase the user manager of the platform
     */
    explicit CurrentSession(UserDatabase *userDatabase);

    /**
     * Tries to log in via a given nickname and password
     *
     * @param nickname the nickname given
     * @param password the password given
     * @return true if it was sucessful, false othewise
     */
    bool login(const std::string& nickname, const std::string& password);

    /**
     * Tries to log out the current usert
     *
     * @return true if it was sucessful, false othewise
     */
    bool logout();

    /**
     * Gets the current User logged int
     *
     * @return the shared pointer to the current user
     */
    [[nodiscard]] const User* getCurrentUser() const;


    /**
     * Gets the nickname of the current user
     *
     * @return the nickname of the current user
     */
    [[nodiscard]] std::string getNickname() const;
};

#endif //PROJECT_CURRENTSESSION_H