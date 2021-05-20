//
// Created by Danny on 17/11/2020.
//

#ifndef PROJECT_NICKNAMENOTFOUND_H
#define PROJECT_NICKNAMENOTFOUND_H

#include <iostream>
#include <exception>
#include <utility>

/**
 * @file nicknameNotFound.cpp
 *
 * @brief Exception for when a viewer being removed couldn't be found
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a viewer being removed from the whitelist of a private stream is not in the whitelist
 *
 * Informs the streamer that the viewer isn't on the whitelist
 */
class NicknameNotFound : public std::invalid_argument {
public:
    /**
     * Constructor of the NicknameNotFound class
     *
     * @param nickname nickname of the viewer being searched
     * @param message message indicating the viewer is not on the whitelist
     */
    NicknameNotFound(std::string nickname, const std::string & message);

    /**
     * Getter of the nickname of the viewer not on the whitelist
     *
     * @return nickname of the viewer not on the whitelist
     */
    const std::string &getNickname() const;

private:
    std::string nickname;
};

#endif //PROJECT_NICKNAMENOTFOUND_H
