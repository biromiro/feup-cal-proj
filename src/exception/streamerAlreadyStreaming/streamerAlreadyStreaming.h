//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_STREAMERALREADYSTREAMING_H
#define PROJECT_STREAMERALREADYSTREAMING_H

#include <iostream>
#include <exception>
#include "../../model/user/streamer/streamer.h"

/**
 * @file streamerAlreadyStreaming.cpp
 *
 * @brief Exception for when a streamer is already streaming
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a streamer is trying to start a stream but is already streaming
 *
 * Informs the streamer that he can't start a stream because he's already streaming
 */
class StreamerAlreadyStreaming : public std::logic_error {
public:
    /**
     * Constructor of the StreamerAlreadyStreaming class
     *
     * @param streamer streamer that is creating a stream while in the middle of one already
     * @param message message indicating the streamer is already streaming
     */
    StreamerAlreadyStreaming(std::shared_ptr<Streamer> streamer, const std::string & message);

    /**
     * Getter of the streamer trying to start a stream
     *
     * @return the streamer trying to start a stream
     */
    [[nodiscard]] const std::shared_ptr<Streamer> &getStreamer() const;

private:
    std::shared_ptr<Streamer> streamer;
};

#endif //PROJECT_STREAMERALREADYSTREAMING_H
