//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_NICKNAMEALREADYADDED_H
#define PROJECT_NICKNAMEALREADYADDED_H

#include <iostream>
#include <exception>

/**
 * @file nicknameAlreadyAdded.cpp
 *
 * @brief Exception for the case where a user tries to register with a nickname already in use
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a user tries to register with a nickname already in use
 *
 * Informs the user that his nickname choice is already taken
 */
class NicknameAlreadyAdded : public std::invalid_argument {
public:
    /**
     * Constructor of the NicknameAlreadyAdded
     *
     * @param nickname nickname already in use
     * @param message message indicating that the nickname chosen is already in use
     */
    NicknameAlreadyAdded(std::string nickname, const std::string & message);

    /**
     * Getter of the nickname already taken
     *
     * @return nickname already taken
     */
    const std::string &getNickname() const;

private:
    std::string nickname;
};

#endif //PROJECT_NICKNAMEALREADYADDED_H
