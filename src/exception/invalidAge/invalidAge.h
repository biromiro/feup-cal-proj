//
// Created by nrtc on 14/11/2020.
//

#ifndef PROJECT_INVALIDAGE_H
#define PROJECT_INVALIDAGE_H

#include <iostream>
#include <exception>

/**
 * @file invalidAge.cpp
 *
 * @brief Exception for when a user tries to register with an age below minimum
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a streamer tries to register but his age is below 15 or
 * a viewer tries to register but his age is below 12
 *
 * Informs the user he's not old enough to register
 */
class InvalidAge : public std::invalid_argument{
public:
    /**
     * Constructor of the InvalidAge class
     *
     * @param age invalid user age
     * @param message message indicating the age of the user is invalid
     */
    InvalidAge(unsigned int age, const std::string &message);

    /**
     * Getter of the invalid user age
     *
     * @return invalid user age
     */
    unsigned int getAge() const;

private:
    unsigned int age;
};

#endif //PROJECT_INVALIDAGE_H
