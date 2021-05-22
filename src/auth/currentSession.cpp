//
// Created by nrtc on 20/05/2021.
//

#include "currentSession.h"


CurrentSession::CurrentSession() : userDatabase(nullptr), currentUser(nullptr){}

CurrentSession::CurrentSession(UserDatabase* userDatabase): userDatabase(userDatabase), currentUser(nullptr){}

bool CurrentSession::login(const std::string& nickname, const std::string& password) {
    auto user = userDatabase->get(nickname);

    //checks if there's not one user already logged in and if the credentials match
    if(user != nullptr && user->getPassword() == password){
        currentUser = user;
        return true;
    }
    return false;
}

bool CurrentSession::logout() {
    if(currentUser != nullptr){
        currentUser = nullptr;
        return true;
    }
    return false;
}
const User* CurrentSession::getCurrentUser() const {
    return currentUser;
}

std::string CurrentSession::getNickname() const {
    return currentUser->getNickname();
}
