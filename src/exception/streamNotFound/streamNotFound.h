//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_STREAMNOTFOUND_H
#define PROJECT_STREAMNOTFOUND_H

#include <iostream>
#include <exception>
#include "../../model/stream/stream.h"

/**
 * @file streamNotFound.cpp
 *
 * @brief Exception for when a stream is not in the list of streams
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a stream is not in the list of streams of the platform
 *
 * Informs the user that the stream searched couldn't be found
 */
class StreamNotFound : public std::invalid_argument {
public:
    /**
     * Constructor of the StreamNotFound class
     *
     * @param stream stream that couldn't be found
     * @param message message indicating that the stream searched was not found
     */
    StreamNotFound(std::shared_ptr<Stream> stream, const std::string & message);

    /**
     * Getter of the stream that couldn't be found
     *
     * @return stream that couldn't be found
     */
    [[nodiscard]] const std::shared_ptr<Stream> &getStream() const;
private:
    std::shared_ptr<Stream> stream;
};


#endif //PROJECT_STREAMNOTFOUND_H
