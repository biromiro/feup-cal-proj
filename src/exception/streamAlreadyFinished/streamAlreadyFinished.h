//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_STREAMALREADYFINISHED_H
#define PROJECT_STREAMALREADYFINISHED_H

#include <iostream>
#include <exception>
#include "../../model/stream/stream.h"

/**
 * @file streamAlreadyFinished.cpp
 *
 * @brief Exception for when a stream trying to be ended has already ended before
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a stream being ended has already finished before
 *
 * Informs the streamer that the stream he's trying to end has already ended
 */
class StreamAlreadyFinished : public std::logic_error {
public:
    /**
     * Constructor of the StreamAlreadyFinished class
     *
     * @param stream stream the streamer is trying to end
     * @param message message indicating that the stream has already ended before
     */
    StreamAlreadyFinished(std::shared_ptr<Stream> stream, const std::string & message);

    /**
     * Getter of the stream the streamer is trying to finish
     *
     * @return stream that can't be finished because it has ended before
     */
    [[nodiscard]] const std::shared_ptr<Stream> &getStream() const;

private:
    std::shared_ptr<Stream> stream;
};

#endif //PROJECT_STREAMALREADYFINISHED_H
