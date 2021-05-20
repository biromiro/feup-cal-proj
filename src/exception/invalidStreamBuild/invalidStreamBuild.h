//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_INVALIDSTREAMBUILD_H
#define PROJECT_INVALIDSTREAMBUILD_H

#include <iostream>
#include <exception>

/**
 * @file invalidStreamBuild.cpp
 *
 * @brief Exception for the case where the stream trying to be created is invalid
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a stream being created is invalid
 *
 * Informs the streamer that the stream he's creating is invalid
 */
class InvalidStreamBuild : public std::runtime_error {
public:
    /**
     * Constructor of the InvalidStreamBuild class
     *
     * @param message message indicating that the stream is invalid
     */
    explicit InvalidStreamBuild(const std::string & message);
};

#endif //PROJECT_INVALIDSTREAMBUILD_H
