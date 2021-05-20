//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_INVALIDSTREAMTOADD_H
#define PROJECT_INVALIDSTREAMTOADD_H

#include <iostream>
#include <exception>
#include "../../model/stream/stream.h"

/**
 * @file invalidStreamToAdd.cpp
 *
 * @brief Exception for the case where the stream trying to be added is invalid or already exists
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a stream being added when being started is invalid or already exists
 *
 * Informs the user that the stream can't be added
 */
class InvalidStreamToAdd : public std::invalid_argument {
public:
    /**
     * Constructor for the InvalidStreamToAdd class
     *
     * @param stream stream that can't be added
     * @param message message indicating the stream can't be added
     */
    InvalidStreamToAdd(std::shared_ptr<Stream> stream, const std::string & message);

    /**
     * Getter of the stream that was unsuccessfully added
     *
     * @return stream unsuccessfully added
     */
    const std::shared_ptr<Stream> &getStream() const;

private:
    std::shared_ptr<Stream> stream;
};

#endif //PROJECT_INVALIDSTREAMTOADD_H
